#ifndef MYEXCEPTION_H
#define MYEXCEPTION_H

#include <string>
#include <exception>
#include <stdexcept>

class MyException : public std::logic_error {
public:
	MyException ( const char* word ) : std::logic_error ( word ) {};
	const char* what ( void ) const noexcept;
};

#endif /* MYEXCEPTION_H */
