/*
 * (C) 2003-2023 Anope Team
 * Contact us at team@anope.org
 *
 * Please read COPYING and README for further details.
 */

namespace WebCPanel
{

namespace NickServ
{

class Access : public WebPanelProtectedPage
{
 public:
	Access(const Anope::string &cat, const Anope::string &u);

	bool OnRequest(HTTPProvider *, const Anope::string &, HTTPClient *, HTTPMessage &, HTTPReply &, NickAlias *, TemplateFileServer::Replacements &) anope_override;
};

}

}
