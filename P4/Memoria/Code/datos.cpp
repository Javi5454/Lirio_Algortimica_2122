ifstream file;
file.open(argv[1]);
string entrada1;
file >> entrada1;
	
string entrada2;
file >> entrada2;
file.close();
	
int n = entrada1.size();
int m = entrada2.size();
