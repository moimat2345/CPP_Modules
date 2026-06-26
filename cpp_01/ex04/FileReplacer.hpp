/*
** CPP - Module 01 - ex04 : Sed is for losers
** FileReplacer.hpp
*/

#ifndef FILEREPLACER_HPP
# define FILEREPLACER_HPP

# include <iostream>
# include <fstream>
# include <sstream>
# include <string>

class FileReplacer
{
private:
	std::string	_filename;
	std::string	_s1;
	std::string	_s2;

	std::string	replaceAll( const std::string& content ) const;

public:
	FileReplacer( std::string filename, std::string s1, std::string s2 );
	~FileReplacer( void );

	bool	run( void ) const;
};

#endif
