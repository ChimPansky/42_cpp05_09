#include <iomanip>
#include <map>
#include <string>
#include <iostream>

// bool	customStrCompare(std::string& lHs, std::string& rHs) {

// }
typedef std::map<std::string, const double> mapStrDbl;
typedef std::pair<const std::string, const double> pairType;

void	customFind(mapStrDbl db, const std::string& key) {
	mapStrDbl::iterator target = db.upper_bound(key);
	std::cout << "customFind(\"" << key << "\"): ";
	if (target != db.begin())
		std::cout << (--target)->second << std::endl;
	else
		std::cout << target->second << std::endl;
}

int main() {
	mapStrDbl db;
	db.insert(std::make_pair(static_cast<const std::string>("2023-11-01"), static_cast<const double>(42.5)));
	db.insert(std::make_pair(static_cast<const std::string>("2023-11-02"), static_cast<const double>(17)));
	db.insert(std::make_pair(static_cast<const std::string>("2023-11-10"), static_cast<const double>(137)));
	db.insert(std::make_pair(static_cast<const std::string>("2023-10-05"), static_cast<const double>(0.5)));
	db.insert(std::make_pair(static_cast<const std::string>("2023-10-21"), static_cast<const double>(7443.3)));
	// db.insert(std::make_pair(static_cast<const std::string>("100"), static_cast<const double>(0.25)));
	// db.insert(std::make_pair(static_cast<const std::string>("0"), static_cast<const double>(44.5)));
	// db.insert(std::make_pair(static_cast<const std::string>("7"), static_cast<const double>(13.0)));

	for (mapStrDbl::const_iterator it
		= db.begin(); it != db.end(); it++) {
			std::cout << it->first << " | " << std::setprecision(2) << it->second << std::endl;	// why are values with no decimal points not displayed as x.00??
	}

	customFind(db, "0000-00-00");
	customFind(db, "9999-00-00");
	customFind(db, "2023-01-31");
	customFind(db, "2022-10-15");
	customFind(db, "2091-05-06");
	customFind(db, "1999-10-10");
	customFind(db, "2024-01-01");

	return 0;

}
