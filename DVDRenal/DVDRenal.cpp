#include "DVDRental.h"

///////////////////////////////////////////////////////////
// Console (cmd) settings: width=120 
// can be changed in RentalStore.h const MENU_WIDTH
///////////////////////////////////////////////////////////
// File paths (movies, accounts) 
// can be changed in ReadFiles.h
///////////////////////////////////////////////////////////

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


