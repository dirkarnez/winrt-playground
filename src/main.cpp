// #pragma comment(lib, "windowsapp")

// #include <winrt/windows.foundation.collections.h>
// #include <winrt/windows.web.syndication.h>
// #include <iostream>

// using namespace winrt;
// using namespace Windows::Foundation;
// using namespace Windows::Web::Syndication;

// int main() 
// {
// 	init_apartment();

// 	Uri url{L"https://user.xmission.com/~legalize/vintage/bitsavers-pdf.xml"};
// 	SyndicationClient client;
// 	SyndicationFeed feed{client.RetrieveFeedAsync(url).get()};
	
// 	for (const auto item : feed.Items())
// 	{
// 		hstring title = item.Title().Text();
// 		std::wcout << title.c_str() << L'\n';
// 	}

// 	std::cin.get();
// 	return 0;
// }


/**
file: HelloWinRT.cpp
by:   Christian Apostoli
org:  FGCU COP 2001 80601
desc: Prints hello world through a graphics window
Link: https://docs.microsoft.com/en-us/windows/uwp/cpp-and-winrt-apis/get-started?view=msvc-160
*/
// HelloWinRT.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <winrt/Windows.Foundation.Collections.h>	//From Windows SDK
#include <winrt/Windows.Web.Syndication.h>			//From Windoes SDK

// #include "pch.h"
//using directives suitable for our new project
using namespace winrt;                           
using namespace Windows::Foundation;
using namespace Windows::Web::Syndication;

int main()
{
    
    //initializes thread in Windows Runtime, intializes COM
    winrt::init_apartment(); 

    //stack-allocate two objects: the uri of windoes blog 
    //and a syndication client
    Uri rssFeedUri{ L"https://blogs.windows.com/feed" };
    SyndicationClient syndicationClient;

    //receives asynchronus operation object from RetrieveFeedAsync and it calls
    //get on that object to block the calling thread and wait for the result
    SyndicationFeed syndicationFeed = syndicationClient.RetrieveFeedAsync(rssFeedUri).get();
    
    //SyndicationFeed.Items is a ranges defined by iterators returned from begin 
    // and enf functions
    for (const SyndicationItem syndicationItem : syndicationFeed.Items())
    {
        //gets the feed title's text 
        winrt::hstring titleAsHstring = syndicationItem.Title().Text();
        std::wcout << titleAsHstring.c_str() << std::endl;
    }

    std::cin.get();
    return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
