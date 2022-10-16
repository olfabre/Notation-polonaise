class expression
{
	friend class evaluate;
	stack<double> pile;
	queue<char> file;
	ifstream filestream;

	public :
		void lecture(char* filename);
		double calcul();
};