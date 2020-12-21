#include "DVDRental.h"

int main()
{
	ReadFiles* file = new ReadFiles;
	
	//read and create objects from file
	store.setAccounts(file->readAccounts());
	store.setMovies(file->readMovies());

	show_menu();

	//save objects to file
	file->saveAccounts(store.getAccounts());
	file->saveMovies(store.getMovies());

	delete file;
	file = NULL;
}


