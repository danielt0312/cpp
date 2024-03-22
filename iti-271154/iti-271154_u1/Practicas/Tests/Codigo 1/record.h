enum MealType { NO_PREF, REGULAR, LOW_FAT, VEGETARIAN, DEFAULT};

class record {
    private:
    	char *name;
    	int course1, course2;
    	double avg;
    	MealType mealPref;
    public:
    	void setPref(int type);
    	MealType getPref();
    	void setCourses(int x, int y);
    	void getAvg();
    	void print (void);
};
