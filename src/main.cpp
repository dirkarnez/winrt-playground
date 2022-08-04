#pragma comment(lib, "windowsapp")

#include <winrt/windows.foundation.collections.h>
#include <winrt/windows.web.syndication.h>
#include <iostream>

using namespace winrt;
using namespace Windows::Foundation;
using namespace Windows::Web::Syndication;

int main() 
{
	init_apartment();

	Uri url{L"https://user.xmission.com/~legalize/vintage/bitsavers-pdf.xml"};
	SyndicationClient client;
	SyndicationFeed feed{client.RetrieveFeedAsync(url).get()};
	
	for (const auto item : feed.Items())
	{
		hstring title = item.Title().Text();
		std::wcout << title.c_str() << L'\n';
	}

	std::cin.get();
	return 0;
}
