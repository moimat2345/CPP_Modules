/*
** CPP - Module 01 - ex04 : Sed is for losers
** FileReplacer.cpp
**
** Reads the whole file, rebuilds the content replacing every s1 with s2 using
** std::string::find + substr (std::string::replace is forbidden), and writes
** the result into <filename>.replace.
*/

#include "FileReplacer.hpp"

FileReplacer::FileReplacer( std::string filename, std::string s1, std::string s2 )
	: _filename(filename), _s1(s1), _s2(s2)
{
	return ;
}

FileReplacer::~FileReplacer( void )
{
	return ;
}

std::string	FileReplacer::replaceAll( const std::string& content ) const
{
	std::string	result;
	size_t		pos = 0;
	size_t		found;

	while ((found = content.find(this->_s1, pos)) != std::string::npos)
	{
		result += content.substr(pos, found - pos);
		result += this->_s2;
		pos = found + this->_s1.length();
	}
	result += content.substr(pos);
	return result;
}

bool	FileReplacer::run( void ) const
{
	std::ifstream	inFile(this->_filename.c_str());
	if (!inFile.is_open())
	{
		std::cerr << "Error: could not open file '" << this->_filename << "'" << "\n";
		return false;
	}

	std::stringstream	buffer;
	buffer << inFile.rdbuf();
	inFile.close();
	std::string	content = buffer.str();

	std::string		outName = this->_filename + ".replace";
	std::ofstream	outFile(outName.c_str());
	if (!outFile.is_open())
	{
		std::cerr << "Error: could not create file '" << outName << "'" << "\n";
		return false;
	}

	outFile << this->replaceAll(content);
	outFile.close();
	return true;
}
