/* c.l syntax highlighter */

%{
/* POSIX for isatty, fileno */
#define _POSIX_C_SOURCE 200112L

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

/* declarations are visible to user actions */

enum FG
{
	fgRED      = 31,   fgGREEN    = 32,
	fgORANGE   = 33,   fgCYAN     = 36,   
	fgDARKGREY = 90,   fgYELLOW   = 93
};

void set_color(enum FG);
void reset_color(void);
void color_print(enum FG, const char *);

void consume_comment(void);
%}

/* named regexes we can use in rules */

O   [0-7]
D   [0-9]
NZ  [1-9]
L   [a-zA-Z_]
A   [a-zA-Z_0-9]
H   [a-fA-F0-9]
HP  (0[xX])
E   ([Ee][+-]?{D}+)
P   ([Pp][+-]?{D}+)
FS  (f|F|l|L)
IS  (((u|U)(l|L|ll|LL)?)|((l|L|ll|LL)(u|U)?))
CP  (u|U|L)
SP  (u8|u|U|L)
ES  (\\(['"\?\\abfnrtv]|[0-7]{1,3}|x[a-fA-F0-9]+))
WS  [ \t\v\n\f]

%%

 /* attempting to match and capture an entire multi-line
    comment could strain lex's buffers, so we match the
    beginning, and call consume_comment() to deal with
    the ensuing characters, in our own less resource-
    intensive way */

"/*"      {
	set_color(fgDARKGREY);

	/* For greater flexibility, we'll output to lex's stream, yyout.
	   It defaults to stdout. */
	fputs(yytext, yyout);

	consume_comment();
	reset_color();
}

 /* single-line comments can be handled the default way.
    The yytext variable is provided by lex and points
    to the characters that match the regex */

"//".*    {
	color_print(fgDARKGREY, yytext);
}

^[ \t]*#.*      {
	color_print(fgRED, yytext);
}

 /* you can use the same code block for multiple regexes */

auto     |
bool     |
char     |
const    |
double   |
enum     |
extern   |
float    |
inline   |
int      |
long     |
register |
restrict |
short    |
size_t   |
signed   |
static   |
struct   |
typedef  |
union    |
unsigned |
void     |
volatile |
_Bool    |
_Complex {
	color_print(fgGREEN, yytext);
}

break    |
case     |
continue |
default  |
do       |
else     |
for      |
goto     |
if       |
return   |
sizeof   |
switch   |
while    {
	color_print(fgYELLOW, yytext);
}

 /* we use the named regexes heavily below; putting
    them in curly brackets expands them */

{L}{A}*  {

	/* without this rule, keywords within larger words
	   would be highlighted, like the "if" in "life" --
	   this rule prevents that because it's a longer match */

	fputs(yytext, yyout);
}

{HP}{H}+{IS}?               |
{NZ}{D}*{IS}?               |
"0"{O}*{IS}?                |
{CP}?"'"([^'\\\n]|{ES})+"'" |
{D}+{E}{FS}?                |
{D}*"."{D}+{E}?{FS}?        |
{D}+"."{E}?{FS}?            |
{HP}{H}+{P}{FS}?            |
{HP}{H}*"."{H}+{P}{FS}?     |
{HP}{H}+"."{P}{FS}?         {
	color_print(fgCYAN, yytext);
}

({SP}?\"([^"\\\n]|{ES})*\"{WS}*)+ {
	color_print(fgORANGE, yytext);
}

 /* explicitly mention the default rule */

. ECHO;

%%

/* definitions of the functions we declared earlier */

/* the color functions use ANSI escape codes, and may
   not be portable across all terminal emulators. */

void set_color(enum FG c)
{
	fprintf(yyout, "\033[%d;1m", c);
}

void reset_color(void)
{
	fputs("\033[0m", yyout);
}

void color_print(enum FG c, const char *s)
{
	set_color(c);
	fputs(s, yyout);
	reset_color();
}

/* this function directly consumes characters in lex
   using the input() function. It pulls characters
   from the same stream that the regex state machine
   reads. */
void consume_comment(void)
{
	int c;

	/* EOF in lex is 0, which is different from
	   the EOF macro in the C standard library */
	while ((c = input()) != 0)
	{
		putchar(c);
		if (c == '*')
		{
			while ((c = input()) == '*')
				putchar(c);
			if (c == 0) break;
			putchar(c);
			if (c == '/') return;
		}
	}
}

int main(void)
{
	if (!isatty(fileno(stdout)))
	{
		/* a more flexible option would be to make the
		   color changing functions do nothing, but that's
		   too much fuss for an example program */

		fputs("Stdout is not a terminal\n", stderr);
		return EXIT_FAILURE;
	}
	/* since we'll be changing terminal color, be sure to
	   reset it for any program termination event */
	atexit(reset_color);

	/* let our lex rules do the rest */
	yylex();
	return EXIT_SUCCESS;
}
