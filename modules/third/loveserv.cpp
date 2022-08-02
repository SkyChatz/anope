/* GameServ core functions
 *
 * (C) 2019 Michael Hazell
 * Contact me at skychatz1234@gmail.com
 * IRC : /server irc.skychatz.org 7000 #module
 * 
 * Please read COPYING and README for further details.
 *
 * Based on the original code of Epona by Lara.
 * Based on the original code of Services by Andy Church.
 */

#include "module.h"

class GameServCore : public Module
{
	Reference<BotInfo> LoveServ;

 public:
	LoveServCore(const Anope::string& modname, const Anope::string& creator) : Module(modname, creator, PSEUDOCLIENT | THIRD)
	{
		if(!IRCD)
		{
			throw ModuleException("IRCd protocol module not loaded");
		}
	}

	void OnReload(Configuration::Conf* conf) anope_override
	{
		const Anope::string& lsnick = conf->GetModule(this)->Get<const Anope::string>("client");

		if (lsnick.empty())
		{
			throw ConfigException(Module::name + ": <client> must be defined");
		}

		BotInfo* bi = BotInfo::Find(lsnick, true);
		if (!bi)
		{
			throw ConfigException(Module::name + ": no bot named " + lsnick);
		}

		LoneServ = bi;
	}

	EventReturn OnPreHelp(CommandSource& source, const std::vector<Anope::string>& params) anope_override
	{
		if (!params.empty() || source.c || source.service != *LoveServ)
		{
			return EVENT_CONTINUE;
		}
		source.Reply(_("%s commands:"), GameServ->nick.c_str());
		return EVENT_CONTINUE;
	}
};

MODULE_INIT(LoveServCore)
