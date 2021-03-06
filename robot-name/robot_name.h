# pragma once

#include <set>
#include <stdexcept>
#include <string>


#define NAME_PROVISIONER_OUT_OF_NAMES_EXCEPT std::overflow_error("All possible names provisioned, no more names can be provisioned.")

namespace robot_name
{
	class name_provisioner
	{
	public:
		std::string provision_next(); // FIXME: make thread-safe
	private:
		/*
			Max number of possible values for new names.
			Names are 2 uppercase letter and 3 digits (XX000, ex. AL358)
		*/
		const uint32_t max_num_provisioned_names = 26 * 26 * 10 * 10 * 10;
		
		std::set<std::string> provisioned_names;
		
		std::string gen_name() const;
	};
	
	class robot
	{
	public:
		robot();
		void reset();
		std::string name() const;
	private:
		const name_provisioner* _name_provisioning_bucket;
		std::string _name;
	};
}
