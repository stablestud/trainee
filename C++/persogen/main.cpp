#include <ctime>
#include <chrono>
#include <cctype>
#include <string>
#include <memory>
#include <random>
#include <iostream>
#include <stdexcept>

#define STRINGIFY(X) STRINGIFY_(X)
#define STRINGIFY_(X) #X


// Only C++20 includes std::chrono::years, so for older versions we create our own
#if __cplusplus <= 201703l
namespace std {
	namespace chrono {
		typedef duration<int, std::ratio<86400>> days;
		typedef duration<int, std::ratio<2629746>> months;
		typedef duration<int, std::ratio<31556952>> years;
	}
}
#endif

using std::chrono::days;
using std::chrono::months;
using std::chrono::years;
using std::chrono::system_clock;


struct sdate {
	sdate(std::string years, std::string months, std::string days);
	std::string stryears;
	std::string strmonths;
	std::string strdays;
};

sdate::sdate(std::string years, std::string months, std::string days)
	: stryears(years), strmonths(months), strdays(days) {}


const std::string genauthorityblock(const std::string authnum, const std::string cardnum);
const std::tm createdate(const years offset, const std::chrono::time_point<system_clock> tnow);
const std::string gendateblock(const std::tm time);
const std::string createdatestring(const std::tm time);
const std::string padnumber(std::string str);
const char genchecksum(const std::string block);
const struct sdate convertdate(const std::tm time);
const int convertcharacter(const char c);


int main(const int argc, const char *const argv[])
{
	constexpr short MAX_AGE = 70;
	constexpr short MIN_AGE = 21;
	constexpr short MAX_VALID = 9;
	constexpr short MIN_VALID = 1;

	try {
		std::random_device rd;
		std::uniform_int_distribution<short> dist_age(MIN_AGE, MAX_AGE);
		std::uniform_int_distribution<short> dist_valid(MIN_VALID, MAX_VALID);

		const years age(dist_age(rd));
		const years valid(dist_valid(rd));
		const std::string authnum("L73Y");
		const std::string cardnum("66280");
		const std::string countrycode("D");

		auto tnow = system_clock::now();
		/* Identification:
		 * 1. Authority Block
		 * 2. Birth Block
		 * 3. Expiration Block
		 * 4. Checksum Block
		 *
		 * Complete length: 36 characters
		 */

		const std::string blk_auth(genauthorityblock(authnum, cardnum));

		const std::tm txt_birth(createdate(-age, tnow));
		const std::tm txt_expiry(createdate(valid, tnow));

		const std::string str_birth(createdatestring(txt_birth));
		const std::string str_expiry(createdatestring(txt_expiry));

		const std::string blk_birth(gendateblock(txt_birth));
		const std::string blk_expiry(gendateblock(txt_expiry));

		const char sum = genchecksum(blk_auth + blk_birth + blk_expiry);

		std::cout << "Day of birth:\t\t" << str_birth << " (age " << age.count() << ")\n"
			<< "Card valid until:\t" << str_expiry << " (" << valid.count() << " years)\n\n";
		std::cout << "Format: new ID card\n";
		std::cout << "IDD<<" << blk_auth << "<<<<<<<<<<<<<<<" << '\n'
			<< blk_birth << '<' << blk_expiry << countrycode << "<<<<<<<<<<<<<" << sum << "\n\n";
		std::cout << "Format: old ID card\n";
		std::cout << blk_auth << "<<" << blk_birth << "<" << blk_expiry << countrycode << "<<<<<" << sum << '\n' << std::endl;
	} catch (std::logic_error &e) {
		std::cout << argv[0] <<  ":" << e.what() << std::endl;
	}
}

const std::string genauthorityblock(const std::string authnum, const std::string cardnum)
{
	std::string str(authnum + cardnum);
	str.push_back(genchecksum(str));

	return str;
}

const std::tm createdate(const years offset, const std::chrono::time_point<system_clock> tnow)
{
	std::chrono::time_point<system_clock> birthpoint(tnow + offset);

	const std::time_t sinceepoch = system_clock::to_time_t(birthpoint);
	return std::tm(*std::localtime(&sinceepoch));
}

const std::string gendateblock(const std::tm time)
{
	std::string str("");

	const struct sdate date(convertdate(time));
	str.append(date.stryears);
	str.append(date.strmonths);
	str.append(date.strdays);

	str.push_back(genchecksum(str));

	if (str.size() != 7)
		throw std::domain_error(__FILE__ ":" STRINGIFY(__LINE__) ": blocksize invalid");

	return str;
}

const std::string createdatestring(const std::tm time)
{
	const struct sdate date(convertdate(time));

	return std::string(date.strdays + "-" +  date.strmonths + "-" + std::to_string(time.tm_year + 1900));
}

const std::string padnumber(std::string str)
{
	if (str.size() > 2 || str.size() < 1)
		throw std::length_error(__FILE__ ":" STRINGIFY(__LINE__) ": cannot pad number");
	else if (str.size() == 1)
		str.insert(0, "0");

	return str;
}

const char genchecksum(const std::string block)
{
	auto it = block.cbegin();
	int sum = 0, mul = 7; 

	while (it != block.cend()) {
		sum += convertcharacter(*(it++)) * mul;
		switch(mul) {
		case 7:
			mul = 3;
			break;
		case 3:
			mul = 1;
			break;
		case 1:
			mul = 7;
			break;
		default:
			throw std::out_of_range(__FILE__ ":" STRINGIFY(__LINE__) ": cannot generate checksum");
			break;
		}
	}

	return sum % 10 + '0';
}

const struct sdate convertdate(const std::tm time)
{
	return sdate(padnumber(std::to_string(time.tm_year % 100)),
			padnumber(std::to_string(time.tm_mon + 1)),
			padnumber(std::to_string(time.tm_mday)));
}

const int convertcharacter(const char c)
{
	if (isdigit(c)) {
		return c - '0';
	} else if (isupper(c)) {
		return c - 'A' + 10;
	} else if (islower(c)) {
		return c - 'a' + 10;
	} else {
		throw std::domain_error(__FILE__ ":" STRINGIFY(__LINE__) ": cannot convert character");
	}
}
