// A Bison parser, made by GNU Bison 3.8.2.

// Skeleton implementation for Bison LALR(1) parsers in C++

// Copyright (C) 2002-2015, 2018-2021 Free Software Foundation, Inc.

// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.

// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.

// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <https://www.gnu.org/licenses/>.

// As a special exception, you may create a larger work that contains
// part or all of the Bison parser skeleton and distribute that work
// under terms of your choice, so long as that work isn't itself a
// parser generator using the skeleton or a modified version thereof
// as a parser skeleton.  Alternatively, if you modify or redistribute
// the parser skeleton itself, you may (at your option) remove this
// special exception, which will cause the skeleton and the resulting
// Bison output files to be licensed under the GNU General Public
// License without this special exception.

// This special exception was added by the Free Software Foundation in
// version 2.2 of Bison.

// DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
// especially those whose name start with YY_ or yy_.  They are
// private implementation details that can be changed or removed.



// First part of user prologue.
#line 1 "grammar.y"

#include <iostream>
#include <string>
#include <cmath>
#include "Scanner1.hpp"

#line 48 "Parser1.cpp"


#include "Parser1.hpp"


// Unqualified %code blocks.
#line 41 "grammar.y"

    namespace calc {
        long long ivars['Z' - 'A' + 1];
        double fvars['z' - 'a' + 1];
     
        long long factorial(long long n) {
            if (n < 2) {
                return 1;
            }
            else {
                return n * factorial(n - 1);
            }
        }
    } // namespace calc

#line 71 "Parser1.cpp"


#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> // FIXME: INFRINGES ON USER NAME SPACE.
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif


// Whether we are compiled with exception support.
#ifndef YY_EXCEPTIONS
# if defined __GNUC__ && !defined __EXCEPTIONS
#  define YY_EXCEPTIONS 0
# else
#  define YY_EXCEPTIONS 1
# endif
#endif



// Enable debugging if requested.
#if YYDEBUG

// A pseudo ostream that takes yydebug_ into account.
# define YYCDEBUG if (yydebug_) (*yycdebug_)

# define YY_SYMBOL_PRINT(Title, Symbol)         \
  do {                                          \
    if (yydebug_)                               \
    {                                           \
      *yycdebug_ << Title << ' ';               \
      yy_print_ (*yycdebug_, Symbol);           \
      *yycdebug_ << '\n';                       \
    }                                           \
  } while (false)

# define YY_REDUCE_PRINT(Rule)          \
  do {                                  \
    if (yydebug_)                       \
      yy_reduce_print_ (Rule);          \
  } while (false)

# define YY_STACK_PRINT()               \
  do {                                  \
    if (yydebug_)                       \
      yy_stack_print_ ();                \
  } while (false)

#else // !YYDEBUG

# define YYCDEBUG if (false) std::cerr
# define YY_SYMBOL_PRINT(Title, Symbol)  YY_USE (Symbol)
# define YY_REDUCE_PRINT(Rule)           static_cast<void> (0)
# define YY_STACK_PRINT()                static_cast<void> (0)

#endif // !YYDEBUG

#define yyerrok         (yyerrstatus_ = 0)
#define yyclearin       (yyla.clear ())

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYRECOVERING()  (!!yyerrstatus_)

#line 14 "grammar.y"
namespace calc {
#line 145 "Parser1.cpp"

  /// Build a parser object.
  Parser::Parser (yyscan_t scanner_yyarg)
#if YYDEBUG
    : yydebug_ (false),
      yycdebug_ (&std::cerr),
#else
    :
#endif
      scanner (scanner_yyarg)
  {}

  Parser::~Parser ()
  {}

  Parser::syntax_error::~syntax_error () YY_NOEXCEPT YY_NOTHROW
  {}

  /*---------.
  | symbol.  |
  `---------*/

  // basic_symbol.
  template <typename Base>
  Parser::basic_symbol<Base>::basic_symbol (const basic_symbol& that)
    : Base (that)
    , value ()
  {
    switch (this->kind ())
    {
      case symbol_kind::S_INTVAR: // INTVAR
      case symbol_kind::S_FLTVAR: // FLTVAR
        value.copy< char > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_FLT: // FLT
      case symbol_kind::S_fexp: // fexp
        value.copy< double > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_INT: // INT
      case symbol_kind::S_iexp: // iexp
        value.copy< long long > (YY_MOVE (that.value));
        break;

      default:
        break;
    }

  }




  template <typename Base>
  Parser::symbol_kind_type
  Parser::basic_symbol<Base>::type_get () const YY_NOEXCEPT
  {
    return this->kind ();
  }


  template <typename Base>
  bool
  Parser::basic_symbol<Base>::empty () const YY_NOEXCEPT
  {
    return this->kind () == symbol_kind::S_YYEMPTY;
  }

  template <typename Base>
  void
  Parser::basic_symbol<Base>::move (basic_symbol& s)
  {
    super_type::move (s);
    switch (this->kind ())
    {
      case symbol_kind::S_INTVAR: // INTVAR
      case symbol_kind::S_FLTVAR: // FLTVAR
        value.move< char > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_FLT: // FLT
      case symbol_kind::S_fexp: // fexp
        value.move< double > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_INT: // INT
      case symbol_kind::S_iexp: // iexp
        value.move< long long > (YY_MOVE (s.value));
        break;

      default:
        break;
    }

  }

  // by_kind.
  Parser::by_kind::by_kind () YY_NOEXCEPT
    : kind_ (symbol_kind::S_YYEMPTY)
  {}

#if 201103L <= YY_CPLUSPLUS
  Parser::by_kind::by_kind (by_kind&& that) YY_NOEXCEPT
    : kind_ (that.kind_)
  {
    that.clear ();
  }
#endif

  Parser::by_kind::by_kind (const by_kind& that) YY_NOEXCEPT
    : kind_ (that.kind_)
  {}

  Parser::by_kind::by_kind (token_kind_type t) YY_NOEXCEPT
    : kind_ (yytranslate_ (t))
  {}



  void
  Parser::by_kind::clear () YY_NOEXCEPT
  {
    kind_ = symbol_kind::S_YYEMPTY;
  }

  void
  Parser::by_kind::move (by_kind& that)
  {
    kind_ = that.kind_;
    that.clear ();
  }

  Parser::symbol_kind_type
  Parser::by_kind::kind () const YY_NOEXCEPT
  {
    return kind_;
  }


  Parser::symbol_kind_type
  Parser::by_kind::type_get () const YY_NOEXCEPT
  {
    return this->kind ();
  }



  // by_state.
  Parser::by_state::by_state () YY_NOEXCEPT
    : state (empty_state)
  {}

  Parser::by_state::by_state (const by_state& that) YY_NOEXCEPT
    : state (that.state)
  {}

  void
  Parser::by_state::clear () YY_NOEXCEPT
  {
    state = empty_state;
  }

  void
  Parser::by_state::move (by_state& that)
  {
    state = that.state;
    that.clear ();
  }

  Parser::by_state::by_state (state_type s) YY_NOEXCEPT
    : state (s)
  {}

  Parser::symbol_kind_type
  Parser::by_state::kind () const YY_NOEXCEPT
  {
    if (state == empty_state)
      return symbol_kind::S_YYEMPTY;
    else
      return YY_CAST (symbol_kind_type, yystos_[+state]);
  }

  Parser::stack_symbol_type::stack_symbol_type ()
  {}

  Parser::stack_symbol_type::stack_symbol_type (YY_RVREF (stack_symbol_type) that)
    : super_type (YY_MOVE (that.state))
  {
    switch (that.kind ())
    {
      case symbol_kind::S_INTVAR: // INTVAR
      case symbol_kind::S_FLTVAR: // FLTVAR
        value.YY_MOVE_OR_COPY< char > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_FLT: // FLT
      case symbol_kind::S_fexp: // fexp
        value.YY_MOVE_OR_COPY< double > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_INT: // INT
      case symbol_kind::S_iexp: // iexp
        value.YY_MOVE_OR_COPY< long long > (YY_MOVE (that.value));
        break;

      default:
        break;
    }

#if 201103L <= YY_CPLUSPLUS
    // that is emptied.
    that.state = empty_state;
#endif
  }

  Parser::stack_symbol_type::stack_symbol_type (state_type s, YY_MOVE_REF (symbol_type) that)
    : super_type (s)
  {
    switch (that.kind ())
    {
      case symbol_kind::S_INTVAR: // INTVAR
      case symbol_kind::S_FLTVAR: // FLTVAR
        value.move< char > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_FLT: // FLT
      case symbol_kind::S_fexp: // fexp
        value.move< double > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_INT: // INT
      case symbol_kind::S_iexp: // iexp
        value.move< long long > (YY_MOVE (that.value));
        break;

      default:
        break;
    }

    // that is emptied.
    that.kind_ = symbol_kind::S_YYEMPTY;
  }

#if YY_CPLUSPLUS < 201103L
  Parser::stack_symbol_type&
  Parser::stack_symbol_type::operator= (const stack_symbol_type& that)
  {
    state = that.state;
    switch (that.kind ())
    {
      case symbol_kind::S_INTVAR: // INTVAR
      case symbol_kind::S_FLTVAR: // FLTVAR
        value.copy< char > (that.value);
        break;

      case symbol_kind::S_FLT: // FLT
      case symbol_kind::S_fexp: // fexp
        value.copy< double > (that.value);
        break;

      case symbol_kind::S_INT: // INT
      case symbol_kind::S_iexp: // iexp
        value.copy< long long > (that.value);
        break;

      default:
        break;
    }

    return *this;
  }

  Parser::stack_symbol_type&
  Parser::stack_symbol_type::operator= (stack_symbol_type& that)
  {
    state = that.state;
    switch (that.kind ())
    {
      case symbol_kind::S_INTVAR: // INTVAR
      case symbol_kind::S_FLTVAR: // FLTVAR
        value.move< char > (that.value);
        break;

      case symbol_kind::S_FLT: // FLT
      case symbol_kind::S_fexp: // fexp
        value.move< double > (that.value);
        break;

      case symbol_kind::S_INT: // INT
      case symbol_kind::S_iexp: // iexp
        value.move< long long > (that.value);
        break;

      default:
        break;
    }

    // that is emptied.
    that.state = empty_state;
    return *this;
  }
#endif

  template <typename Base>
  void
  Parser::yy_destroy_ (const char* yymsg, basic_symbol<Base>& yysym) const
  {
    if (yymsg)
      YY_SYMBOL_PRINT (yymsg, yysym);
  }

#if YYDEBUG
  template <typename Base>
  void
  Parser::yy_print_ (std::ostream& yyo, const basic_symbol<Base>& yysym) const
  {
    std::ostream& yyoutput = yyo;
    YY_USE (yyoutput);
    if (yysym.empty ())
      yyo << "empty symbol";
    else
      {
        symbol_kind_type yykind = yysym.kind ();
        yyo << (yykind < YYNTOKENS ? "token" : "nterm")
            << ' ' << yysym.name () << " (";
        YY_USE (yykind);
        yyo << ')';
      }
  }
#endif

  void
  Parser::yypush_ (const char* m, YY_MOVE_REF (stack_symbol_type) sym)
  {
    if (m)
      YY_SYMBOL_PRINT (m, sym);
    yystack_.push (YY_MOVE (sym));
  }

  void
  Parser::yypush_ (const char* m, state_type s, YY_MOVE_REF (symbol_type) sym)
  {
#if 201103L <= YY_CPLUSPLUS
    yypush_ (m, stack_symbol_type (s, std::move (sym)));
#else
    stack_symbol_type ss (s, sym);
    yypush_ (m, ss);
#endif
  }

  void
  Parser::yypop_ (int n) YY_NOEXCEPT
  {
    yystack_.pop (n);
  }

#if YYDEBUG
  std::ostream&
  Parser::debug_stream () const
  {
    return *yycdebug_;
  }

  void
  Parser::set_debug_stream (std::ostream& o)
  {
    yycdebug_ = &o;
  }


  Parser::debug_level_type
  Parser::debug_level () const
  {
    return yydebug_;
  }

  void
  Parser::set_debug_level (debug_level_type l)
  {
    yydebug_ = l;
  }
#endif // YYDEBUG

  Parser::state_type
  Parser::yy_lr_goto_state_ (state_type yystate, int yysym)
  {
    int yyr = yypgoto_[yysym - YYNTOKENS] + yystate;
    if (0 <= yyr && yyr <= yylast_ && yycheck_[yyr] == yystate)
      return yytable_[yyr];
    else
      return yydefgoto_[yysym - YYNTOKENS];
  }

  bool
  Parser::yy_pact_value_is_default_ (int yyvalue) YY_NOEXCEPT
  {
    return yyvalue == yypact_ninf_;
  }

  bool
  Parser::yy_table_value_is_error_ (int yyvalue) YY_NOEXCEPT
  {
    return yyvalue == yytable_ninf_;
  }

  int
  Parser::operator() ()
  {
    return parse ();
  }

  int
  Parser::parse ()
  {
    int yyn;
    /// Length of the RHS of the rule being reduced.
    int yylen = 0;

    // Error handling.
    int yynerrs_ = 0;
    int yyerrstatus_ = 0;

    /// The lookahead symbol.
    symbol_type yyla;

    /// The return value of parse ().
    int yyresult;

#if YY_EXCEPTIONS
    try
#endif // YY_EXCEPTIONS
      {
    YYCDEBUG << "Starting parse\n";


    /* Initialize the stack.  The initial state will be set in
       yynewstate, since the latter expects the semantical and the
       location values to have been already stored, initialize these
       stacks with a primary value.  */
    yystack_.clear ();
    yypush_ (YY_NULLPTR, 0, YY_MOVE (yyla));

  /*-----------------------------------------------.
  | yynewstate -- push a new symbol on the stack.  |
  `-----------------------------------------------*/
  yynewstate:
    YYCDEBUG << "Entering state " << int (yystack_[0].state) << '\n';
    YY_STACK_PRINT ();

    // Accept?
    if (yystack_[0].state == yyfinal_)
      YYACCEPT;

    goto yybackup;


  /*-----------.
  | yybackup.  |
  `-----------*/
  yybackup:
    // Try to take a decision without lookahead.
    yyn = yypact_[+yystack_[0].state];
    if (yy_pact_value_is_default_ (yyn))
      goto yydefault;

    // Read a lookahead token.
    if (yyla.empty ())
      {
        YYCDEBUG << "Reading a token\n";
#if YY_EXCEPTIONS
        try
#endif // YY_EXCEPTIONS
          {
            yyla.kind_ = yytranslate_ (yylex (&yyla.value, scanner));
          }
#if YY_EXCEPTIONS
        catch (const syntax_error& yyexc)
          {
            YYCDEBUG << "Caught exception: " << yyexc.what() << '\n';
            error (yyexc);
            goto yyerrlab1;
          }
#endif // YY_EXCEPTIONS
      }
    YY_SYMBOL_PRINT ("Next token is", yyla);

    if (yyla.kind () == symbol_kind::S_YYerror)
    {
      // The scanner already issued an error message, process directly
      // to error recovery.  But do not keep the error token as
      // lookahead, it is too special and may lead us to an endless
      // loop in error recovery. */
      yyla.kind_ = symbol_kind::S_YYUNDEF;
      goto yyerrlab1;
    }

    /* If the proper action on seeing token YYLA.TYPE is to reduce or
       to detect an error, take that action.  */
    yyn += yyla.kind ();
    if (yyn < 0 || yylast_ < yyn || yycheck_[yyn] != yyla.kind ())
      {
        goto yydefault;
      }

    // Reduce or error.
    yyn = yytable_[yyn];
    if (yyn <= 0)
      {
        if (yy_table_value_is_error_ (yyn))
          goto yyerrlab;
        yyn = -yyn;
        goto yyreduce;
      }

    // Count tokens shifted since error; after three, turn off error status.
    if (yyerrstatus_)
      --yyerrstatus_;

    // Shift the lookahead token.
    yypush_ ("Shifting", state_type (yyn), YY_MOVE (yyla));
    goto yynewstate;


  /*-----------------------------------------------------------.
  | yydefault -- do the default action for the current state.  |
  `-----------------------------------------------------------*/
  yydefault:
    yyn = yydefact_[+yystack_[0].state];
    if (yyn == 0)
      goto yyerrlab;
    goto yyreduce;


  /*-----------------------------.
  | yyreduce -- do a reduction.  |
  `-----------------------------*/
  yyreduce:
    yylen = yyr2_[yyn];
    {
      stack_symbol_type yylhs;
      yylhs.state = yy_lr_goto_state_ (yystack_[yylen].state, yyr1_[yyn]);
      /* Variants are always initialized to an empty instance of the
         correct type. The default '$$ = $1' action is NOT applied
         when using variants.  */
      switch (yyr1_[yyn])
    {
      case symbol_kind::S_INTVAR: // INTVAR
      case symbol_kind::S_FLTVAR: // FLTVAR
        yylhs.value.emplace< char > ();
        break;

      case symbol_kind::S_FLT: // FLT
      case symbol_kind::S_fexp: // fexp
        yylhs.value.emplace< double > ();
        break;

      case symbol_kind::S_INT: // INT
      case symbol_kind::S_iexp: // iexp
        yylhs.value.emplace< long long > ();
        break;

      default:
        break;
    }



      // Perform the reduction.
      YY_REDUCE_PRINT (yyn);
#if YY_EXCEPTIONS
      try
#endif // YY_EXCEPTIONS
        {
          switch (yyn)
            {
  case 4: // line: EOL
#line 63 "grammar.y"
                                    { std::cerr << "Read an empty line.\n"; }
#line 725 "Parser1.cpp"
    break;

  case 5: // line: iexp EOL
#line 64 "grammar.y"
                                    { std::cout << yystack_[1].value.as < long long > () << '\n'; }
#line 731 "Parser1.cpp"
    break;

  case 6: // line: fexp EOL
#line 65 "grammar.y"
                                    { std::cout << yystack_[1].value.as < double > () << '\n'; }
#line 737 "Parser1.cpp"
    break;

  case 7: // line: INTVAR ASSIGN iexp EOL
#line 66 "grammar.y"
                                    { ivars[yystack_[3].value.as < char > () - 'A'] = yystack_[1].value.as < long long > (); }
#line 743 "Parser1.cpp"
    break;

  case 8: // line: FLTVAR ASSIGN fexp EOL
#line 67 "grammar.y"
                                    { fvars[yystack_[3].value.as < char > () - 'a'] = yystack_[1].value.as < double > (); }
#line 749 "Parser1.cpp"
    break;

  case 9: // line: error EOL
#line 68 "grammar.y"
                                    { yyerrok; }
#line 755 "Parser1.cpp"
    break;

  case 10: // iexp: INT
#line 71 "grammar.y"
                                    { yylhs.value.as < long long > () = yystack_[0].value.as < long long > (); }
#line 761 "Parser1.cpp"
    break;

  case 11: // iexp: iexp PLUS iexp
#line 72 "grammar.y"
                                    { yylhs.value.as < long long > () = yystack_[2].value.as < long long > () + yystack_[0].value.as < long long > (); }
#line 767 "Parser1.cpp"
    break;

  case 12: // iexp: iexp MINUS iexp
#line 73 "grammar.y"
                                    { yylhs.value.as < long long > () = yystack_[2].value.as < long long > () - yystack_[0].value.as < long long > (); }
#line 773 "Parser1.cpp"
    break;

  case 13: // iexp: iexp MULTIPLY iexp
#line 74 "grammar.y"
                                    { yylhs.value.as < long long > () = yystack_[2].value.as < long long > () * yystack_[0].value.as < long long > (); }
#line 779 "Parser1.cpp"
    break;

  case 14: // iexp: iexp DIVIDE iexp
#line 75 "grammar.y"
                                    { yylhs.value.as < long long > () = yystack_[2].value.as < long long > () / yystack_[0].value.as < long long > (); }
#line 785 "Parser1.cpp"
    break;

  case 15: // iexp: iexp MODULO iexp
#line 76 "grammar.y"
                                    { yylhs.value.as < long long > () = yystack_[2].value.as < long long > () % yystack_[0].value.as < long long > (); }
#line 791 "Parser1.cpp"
    break;

  case 16: // iexp: MINUS iexp
#line 77 "grammar.y"
                                    { yylhs.value.as < long long > () = -yystack_[0].value.as < long long > (); }
#line 797 "Parser1.cpp"
    break;

  case 17: // iexp: iexp FACTORIAL
#line 78 "grammar.y"
                                    { yylhs.value.as < long long > () = factorial(yystack_[1].value.as < long long > ()); }
#line 803 "Parser1.cpp"
    break;

  case 18: // iexp: LPAREN iexp RPAREN
#line 79 "grammar.y"
                                    { yylhs.value.as < long long > () = yystack_[1].value.as < long long > (); }
#line 809 "Parser1.cpp"
    break;

  case 19: // iexp: INTVAR
#line 80 "grammar.y"
                                    { yylhs.value.as < long long > () = ivars[yystack_[0].value.as < char > () - 'A']; }
#line 815 "Parser1.cpp"
    break;

  case 20: // fexp: FLT
#line 83 "grammar.y"
                                    { yylhs.value.as < double > () = yystack_[0].value.as < double > (); }
#line 821 "Parser1.cpp"
    break;

  case 21: // fexp: fexp PLUS fexp
#line 84 "grammar.y"
                                    { yylhs.value.as < double > () = yystack_[2].value.as < double > () + yystack_[0].value.as < double > (); }
#line 827 "Parser1.cpp"
    break;

  case 22: // fexp: fexp MINUS fexp
#line 85 "grammar.y"
                                    { yylhs.value.as < double > () = yystack_[2].value.as < double > () - yystack_[0].value.as < double > (); }
#line 833 "Parser1.cpp"
    break;

  case 23: // fexp: fexp MULTIPLY fexp
#line 86 "grammar.y"
                                    { yylhs.value.as < double > () = yystack_[2].value.as < double > () * yystack_[0].value.as < double > (); }
#line 839 "Parser1.cpp"
    break;

  case 24: // fexp: fexp DIVIDE fexp
#line 87 "grammar.y"
                                    { yylhs.value.as < double > () = yystack_[2].value.as < double > () / yystack_[0].value.as < double > (); }
#line 845 "Parser1.cpp"
    break;

  case 25: // fexp: fexp EXPONENT fexp
#line 88 "grammar.y"
                                    { yylhs.value.as < double > () = pow(yystack_[2].value.as < double > (), yystack_[0].value.as < double > ()); }
#line 851 "Parser1.cpp"
    break;

  case 26: // fexp: MINUS fexp
#line 89 "grammar.y"
                                    { yylhs.value.as < double > () = -yystack_[0].value.as < double > (); }
#line 857 "Parser1.cpp"
    break;

  case 27: // fexp: LPAREN fexp RPAREN
#line 90 "grammar.y"
                                    { yylhs.value.as < double > () = yystack_[1].value.as < double > (); }
#line 863 "Parser1.cpp"
    break;

  case 28: // fexp: FLTVAR
#line 91 "grammar.y"
                                    { yylhs.value.as < double > () = fvars[yystack_[0].value.as < char > () - 'a']; }
#line 869 "Parser1.cpp"
    break;


#line 873 "Parser1.cpp"

            default:
              break;
            }
        }
#if YY_EXCEPTIONS
      catch (const syntax_error& yyexc)
        {
          YYCDEBUG << "Caught exception: " << yyexc.what() << '\n';
          error (yyexc);
          YYERROR;
        }
#endif // YY_EXCEPTIONS
      YY_SYMBOL_PRINT ("-> $$ =", yylhs);
      yypop_ (yylen);
      yylen = 0;

      // Shift the result of the reduction.
      yypush_ (YY_NULLPTR, YY_MOVE (yylhs));
    }
    goto yynewstate;


  /*--------------------------------------.
  | yyerrlab -- here on detecting error.  |
  `--------------------------------------*/
  yyerrlab:
    // If not already recovering from an error, report this error.
    if (!yyerrstatus_)
      {
        ++yynerrs_;
        std::string msg = YY_("syntax error");
        error (YY_MOVE (msg));
      }


    if (yyerrstatus_ == 3)
      {
        /* If just tried and failed to reuse lookahead token after an
           error, discard it.  */

        // Return failure if at end of input.
        if (yyla.kind () == symbol_kind::S_YYEOF)
          YYABORT;
        else if (!yyla.empty ())
          {
            yy_destroy_ ("Error: discarding", yyla);
            yyla.clear ();
          }
      }

    // Else will try to reuse lookahead token after shifting the error token.
    goto yyerrlab1;


  /*---------------------------------------------------.
  | yyerrorlab -- error raised explicitly by YYERROR.  |
  `---------------------------------------------------*/
  yyerrorlab:
    /* Pacify compilers when the user code never invokes YYERROR and
       the label yyerrorlab therefore never appears in user code.  */
    if (false)
      YYERROR;

    /* Do not reclaim the symbols of the rule whose action triggered
       this YYERROR.  */
    yypop_ (yylen);
    yylen = 0;
    YY_STACK_PRINT ();
    goto yyerrlab1;


  /*-------------------------------------------------------------.
  | yyerrlab1 -- common code for both syntax error and YYERROR.  |
  `-------------------------------------------------------------*/
  yyerrlab1:
    yyerrstatus_ = 3;   // Each real token shifted decrements this.
    // Pop stack until we find a state that shifts the error token.
    for (;;)
      {
        yyn = yypact_[+yystack_[0].state];
        if (!yy_pact_value_is_default_ (yyn))
          {
            yyn += symbol_kind::S_YYerror;
            if (0 <= yyn && yyn <= yylast_
                && yycheck_[yyn] == symbol_kind::S_YYerror)
              {
                yyn = yytable_[yyn];
                if (0 < yyn)
                  break;
              }
          }

        // Pop the current state because it cannot handle the error token.
        if (yystack_.size () == 1)
          YYABORT;

        yy_destroy_ ("Error: popping", yystack_[0]);
        yypop_ ();
        YY_STACK_PRINT ();
      }
    {
      stack_symbol_type error_token;


      // Shift the error token.
      error_token.state = state_type (yyn);
      yypush_ ("Shifting", YY_MOVE (error_token));
    }
    goto yynewstate;


  /*-------------------------------------.
  | yyacceptlab -- YYACCEPT comes here.  |
  `-------------------------------------*/
  yyacceptlab:
    yyresult = 0;
    goto yyreturn;


  /*-----------------------------------.
  | yyabortlab -- YYABORT comes here.  |
  `-----------------------------------*/
  yyabortlab:
    yyresult = 1;
    goto yyreturn;


  /*-----------------------------------------------------.
  | yyreturn -- parsing is finished, return the result.  |
  `-----------------------------------------------------*/
  yyreturn:
    if (!yyla.empty ())
      yy_destroy_ ("Cleanup: discarding lookahead", yyla);

    /* Do not reclaim the symbols of the rule whose action triggered
       this YYABORT or YYACCEPT.  */
    yypop_ (yylen);
    YY_STACK_PRINT ();
    while (1 < yystack_.size ())
      {
        yy_destroy_ ("Cleanup: popping", yystack_[0]);
        yypop_ ();
      }

    return yyresult;
  }
#if YY_EXCEPTIONS
    catch (...)
      {
        YYCDEBUG << "Exception caught: cleaning lookahead and stack\n";
        // Do not try to display the values of the reclaimed symbols,
        // as their printers might throw an exception.
        if (!yyla.empty ())
          yy_destroy_ (YY_NULLPTR, yyla);

        while (1 < yystack_.size ())
          {
            yy_destroy_ (YY_NULLPTR, yystack_[0]);
            yypop_ ();
          }
        throw;
      }
#endif // YY_EXCEPTIONS
  }

  void
  Parser::error (const syntax_error& yyexc)
  {
    error (yyexc.what ());
  }

#if YYDEBUG || 0
  const char *
  Parser::symbol_name (symbol_kind_type yysymbol)
  {
    return yytname_[yysymbol];
  }
#endif // #if YYDEBUG || 0









  const signed char Parser::yypact_ninf_ = -11;

  const signed char Parser::yytable_ninf_ = -1;

  const signed char
  Parser::yypact_[] =
  {
     -11,    78,   -11,    -2,   -11,    95,   -11,   -11,    -5,    -3,
      95,   -11,    44,     3,   -11,   -11,   -11,    83,    62,   102,
     108,    -7,    -6,   -11,   102,   102,   102,   102,   102,   -11,
     -11,   108,   108,   108,   108,   108,   -11,   -11,   102,   102,
      51,   108,   108,    32,   109,   109,    -7,    -7,    -7,   -10,
     -10,    -6,    -6,    -6,   -11,   -11
  };

  const signed char
  Parser::yydefact_[] =
  {
       2,     0,     1,     0,     4,     0,    10,    20,    19,    28,
       0,     3,     0,     0,     9,    19,    28,     0,     0,     0,
       0,    16,    26,     5,     0,     0,     0,     0,     0,    17,
       6,     0,     0,     0,     0,     0,    18,    27,     0,     0,
       0,     0,     0,     0,    11,    12,    13,    14,    15,    21,
      22,    23,    24,    25,     7,     8
  };

  const signed char
  Parser::yypgoto_[] =
  {
     -11,   -11,   -11,     1,    -1
  };

  const signed char
  Parser::yydefgoto_[] =
  {
       0,     1,    11,    17,    18
  };

  const signed char
  Parser::yytable_[] =
  {
      13,    14,    12,    33,    34,    19,    30,    20,    35,    22,
      29,    21,    35,     0,    31,    32,    33,    34,     0,    43,
      40,    35,     0,     0,     0,    44,    45,    46,    47,    48,
      49,    50,    51,    52,    53,    55,     0,     0,     0,     0,
      21,    22,     0,    31,    32,    33,    34,    23,     0,     0,
      35,     0,     0,     0,    54,    24,    25,    26,    27,    28,
       0,    29,    24,    25,    26,    27,    28,    37,    29,     0,
       0,     0,     0,    31,    32,    33,    34,     0,     2,     3,
      35,     4,     5,     0,     6,     7,     8,     9,    36,     0,
      10,     0,     0,     0,    24,    25,    26,    27,    28,     5,
      29,     6,     7,    15,    16,     0,    38,    10,     6,     0,
      15,     0,    41,     0,    39,     7,     0,    16,     0,     0,
      42,     0,    26,    27,    28,     0,    29
  };

  const signed char
  Parser::yycheck_[] =
  {
       1,     3,     1,    13,    14,    10,     3,    10,    18,    10,
      17,    10,    18,    -1,    11,    12,    13,    14,    -1,    20,
      19,    18,    -1,    -1,    -1,    24,    25,    26,    27,    28,
      31,    32,    33,    34,    35,     3,    -1,    -1,    -1,    -1,
      39,    42,    -1,    11,    12,    13,    14,     3,    -1,    -1,
      18,    -1,    -1,    -1,     3,    11,    12,    13,    14,    15,
      -1,    17,    11,    12,    13,    14,    15,     5,    17,    -1,
      -1,    -1,    -1,    11,    12,    13,    14,    -1,     0,     1,
      18,     3,     4,    -1,     6,     7,     8,     9,     5,    -1,
      12,    -1,    -1,    -1,    11,    12,    13,    14,    15,     4,
      17,     6,     7,     8,     9,    -1,     4,    12,     6,    -1,
       8,    -1,     4,    -1,    12,     7,    -1,     9,    -1,    -1,
      12,    -1,    13,    14,    15,    -1,    17
  };

  const signed char
  Parser::yystos_[] =
  {
       0,    20,     0,     1,     3,     4,     6,     7,     8,     9,
      12,    21,    22,    23,     3,     8,     9,    22,    23,    10,
      10,    22,    23,     3,    11,    12,    13,    14,    15,    17,
       3,    11,    12,    13,    14,    18,     5,     5,     4,    12,
      22,     4,    12,    23,    22,    22,    22,    22,    22,    23,
      23,    23,    23,    23,     3,     3
  };

  const signed char
  Parser::yyr1_[] =
  {
       0,    19,    20,    20,    21,    21,    21,    21,    21,    21,
      22,    22,    22,    22,    22,    22,    22,    22,    22,    22,
      23,    23,    23,    23,    23,    23,    23,    23,    23
  };

  const signed char
  Parser::yyr2_[] =
  {
       0,     2,     0,     2,     1,     2,     2,     4,     4,     2,
       1,     3,     3,     3,     3,     3,     2,     2,     3,     1,
       1,     3,     3,     3,     3,     3,     2,     3,     1
  };


#if YYDEBUG
  // YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
  // First, the terminals, then, starting at \a YYNTOKENS, nonterminals.
  const char*
  const Parser::yytname_[] =
  {
  "\"end of file\"", "error", "\"invalid token\"", "EOL", "LPAREN",
  "RPAREN", "INT", "FLT", "INTVAR", "FLTVAR", "ASSIGN", "PLUS", "MINUS",
  "MULTIPLY", "DIVIDE", "MODULO", "UMINUS", "FACTORIAL", "EXPONENT",
  "$accept", "lines", "line", "iexp", "fexp", YY_NULLPTR
  };
#endif


#if YYDEBUG
  const signed char
  Parser::yyrline_[] =
  {
       0,    59,    59,    60,    63,    64,    65,    66,    67,    68,
      71,    72,    73,    74,    75,    76,    77,    78,    79,    80,
      83,    84,    85,    86,    87,    88,    89,    90,    91
  };

  void
  Parser::yy_stack_print_ () const
  {
    *yycdebug_ << "Stack now";
    for (stack_type::const_iterator
           i = yystack_.begin (),
           i_end = yystack_.end ();
         i != i_end; ++i)
      *yycdebug_ << ' ' << int (i->state);
    *yycdebug_ << '\n';
  }

  void
  Parser::yy_reduce_print_ (int yyrule) const
  {
    int yylno = yyrline_[yyrule];
    int yynrhs = yyr2_[yyrule];
    // Print the symbols being reduced, and their result.
    *yycdebug_ << "Reducing stack by rule " << yyrule - 1
               << " (line " << yylno << "):\n";
    // The symbols being reduced.
    for (int yyi = 0; yyi < yynrhs; yyi++)
      YY_SYMBOL_PRINT ("   $" << yyi + 1 << " =",
                       yystack_[(yynrhs) - (yyi + 1)]);
  }
#endif // YYDEBUG

  Parser::symbol_kind_type
  Parser::yytranslate_ (int t) YY_NOEXCEPT
  {
    // YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to
    // TOKEN-NUM as returned by yylex.
    static
    const signed char
    translate_table[] =
    {
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18
    };
    // Last valid token kind.
    const int code_max = 273;

    if (t <= 0)
      return symbol_kind::S_YYEOF;
    else if (t <= code_max)
      return static_cast <symbol_kind_type> (translate_table[t]);
    else
      return symbol_kind::S_YYUNDEF;
  }

#line 14 "grammar.y"
} // calc
#line 1265 "Parser1.cpp"

#line 94 "grammar.y"

 
void calc::Parser::error(const std::string& msg) {
    std::cerr << msg << '\n';
}
