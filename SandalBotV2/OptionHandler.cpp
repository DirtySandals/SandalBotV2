#include "OptionHandler.h"
#include "Bot.h"

OptionHandler::OptionHandler(Bot* bot) {
	this->bot = bot;
	initOptions();
}

void OptionHandler::initOptions() {
	Option clearHash = {
		"Clear Hash",
		"type buttton",
		[this](std::string& value) {
			this->bot->clearHash();
		}
	};

	options[clearHash.name] = clearHash;

	Option changeHashSize = {
		"Hash",
		"type spin default 1000 min 1 max 2000",
		[this](std::string& value) {
			int valueInt = std::stoi(value);
			if (valueInt < 1 || valueInt > 2000) {
				return;
			}
			this->bot->changeHashSize(valueInt);
		}
	};

	options[changeHashSize.name] = changeHashSize;
}

void OptionHandler::processOption(std::string optionName, std::string value) {
	if (options.find(optionName) == options.end()) {
		return;
	}

	options[optionName].changeSettings(value);
}

std::string OptionHandler::getOptionsString() {
	std::string optionsString = "";
	for (auto& pair : options) {
		optionsString += "option name " + pair.first + " " + pair.second.description + "\n";
	}
	if (optionsString.size() > 0) {
		optionsString.pop_back();
	}
	return optionsString;
}