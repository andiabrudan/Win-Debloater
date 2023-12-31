#include "service.h"

class voidbuff : public std::streambuf {};
voidbuff nostreambuff;
std::ostream devnull(&nostreambuff);
const int LOG_LEVEL = 1;
inline std::ostream& log(int level)
{
	if (level >= LOG_LEVEL)
		return std::cout;
	else
		return devnull;
}

void ChangeRegistryNumber(HKEY machine, std::string_view key, std::string_view value, DWORD data)
{
	try
	{
		log(1) << "Attempting to change: " << reg::except::toString(machine, key, value) << "; desired data: " << data << "\n";
		if (reg::key_exists(machine, key))
		{
			log(2) << "Key \"" << key << "\" already exists\n";
			if (reg::value_exists(machine, key, value))
			{
				DWORD old_data = reg::query::number(machine, key, value);
				log(2) << "Value \"" << value << "\" already exists; current data: " << old_data << "\n";
				if (old_data != data)
				{
					reg::security::take_ownership(machine, key);
					reg::security::set_full_access_rights(machine, key);
					reg::update::number(machine, key, value, data);
					log(4) << "Successfully updated " << value << " (was " << old_data << ")\n";
				}
				else
				{
					log(3) << "No change needed for \"" << value << "\"\n";
				}
			}
			else
			{
				log(2) << "Value \"" << value << "\" does not exist\n";
				reg::security::take_ownership(machine, key);
				reg::security::set_full_access_rights(machine, key);
				reg::create::number(machine, key, value, data);
				log(4) << "Successfully created new value \"" << value << "\" and assigned data: " << data << "\n";
			}
		}
		else
		{
			log(2) << "Key \"" << key << "\" does not exist\n";
			reg::create::key(machine, key);
			log(2) << "Creating value \"" << value << "\"\n";
			reg::create::number(machine, key, value, data);
			log(4) << "Successfully created new value \"" << value << "\" and assigned data: " << data << "\n";
		}
	}
	catch (const std::exception& e)
	{
		log(2) << "An exception occurred while trying to edit \"" << reg::except::toString(machine, key, value) << "\"\n";
		log(4) << e.what() << " --- while trying to edit value \"" << value << "\"\n";
	}
	log(4) << "\n";
}

void ChangeRegistryString(HKEY machine, std::string_view key, std::string_view value, std::string_view data)
{
	try
	{
		log(1) << "Attempting to change: " << reg::except::toString(machine, key, value) << "; desired data: \"" << data << "\"\n";
		if (reg::key_exists(machine, key))
		{
			log(2) << "Key \"" << key << "\" already exists\n";
			if (reg::value_exists(machine, key, value))
			{
				std::string old_data = reg::query::string(machine, key, value);
				log(2) << "Value \"" << value << "\" already exists; current data: \"" << old_data << "\"\n";
				if (old_data != data)
				{
					reg::security::take_ownership(machine, key);
					reg::security::set_full_access_rights(machine, key);
					reg::update::string(machine, key, value, data);
					log(4) << "Successfully updated " << value << " (was \"" << old_data << "\")\n";
				}
				else
				{
					log(3) << "No change needed for \"" << value << "\"\n";
				}
			}
			else
			{
				log(2) << "Value \"" << value << "\" does not exist\n";
				reg::security::take_ownership(machine, key);
				reg::security::set_full_access_rights(machine, key);
				reg::create::string(machine, key, value, data);
				log(4) << "Successfully created new value \"" << value << "\" and assigned data: \"" << data << "\"\n";
			}
		}
		else
		{
			log(2) << "Key \"" << key << "\" does not exist\n";
			reg::create::key(machine, key);
			log(2) << "Creating value \"" << value << "\"\n";
			reg::create::string(machine, key, value, data);
			log(4) << "Successfully created new value \"" << value << "\" and assigned data: \"" << data << "\"\n";
		}
	}
	catch (const std::exception& e)
	{
		log(2) << "An exception occurred while trying to edit \"" << reg::except::toString(machine, key, value) << "\"\n";
		log(4) << e.what() << " --- while trying to edit value \"" << value << "\"\n";
	}
	log(4) << "\n";
}

void Delete_RegistryValue(HKEY machine, std::string_view key, std::string_view value)
{
	const std::string valueName = reg::except::toString(machine, key, value);
	try
	{
		log(1) << "Attempting to delete: " << valueName << "\"\n";
		if (reg::key_exists(machine, key))
		{
			const bool success = reg::remove::value(machine, key, value);
			if (success)
			{
				log(4) << "Successfully removed value \"" << valueName << "\"\n";
			}
			else
			{
				log(4) << "Could not remove value \"" << valueName << "\"\n";
			}
		}
		else
		{
			log(4) << "The value \"" << valueName << "\" was not found.\n";
		}
	}
	catch (const std::exception& e)
	{
		log(2) << "An exception occurred while trying to remove \"" << valueName << "\"\n";
		log(4) << e.what() << " --- while trying to remove \"" << value << "\"\n";
	}
	log(4) << "\n";
}
