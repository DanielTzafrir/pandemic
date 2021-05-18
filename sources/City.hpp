#pragma once
#include <vector>
#include <string>

using namespace std;
namespace pandemic {

const int CITIES_PER_COLOR  = 12;
const int CITIES = 48;
	
    enum City {
        // Red
        Beijing = 0,
        Seoul,
        Tokyo,
        Shanghai,
        HongKong,
        Osaka,
        Taipei,
        Bangkok,
        Manila,
        HoChiMinhCity,
        Jakarta,
        Sydney,

        // Yellow
        LosAngeles,
        MexicoCity,
        Miami,
        Bogota,
        Lima,
        Santiago,
        SaoPaulo,
        BuenosAires,
        Lagos,
        Kinshasa,
        Khartoum,
        Johannesburg,

        //Black
        Moscow,
        Tehran,
        Delhi,
        Kolkata,
        Chennai,
        Mumbai,
        Karachi,
        Baghdad,
        Riyadh,
        Cairo,
        Algiers,
        Istanbul,

        //Blue
        SanFrancisco,
        Chicago,
        Montreal,
        Atlanta,
        NewYork,
        Washington,
        Madrid,
        London,
        Paris,
        Essen,
        Milan,
        StPetersburg,
    };

    const vector<string> cityNames = 
    {
        "Beijing",
        "Seoul",
        "Tokyo",
        "Shanghai",
        "HongKong",
        "Osaka",
        "Taipei",
        "Bangkok",
        "Manila",
        "HoChiMinhCity",
        "Jakarta",
        "Sydney",

         "LosAngeles",
        "MexicoCity",
        "Miami",
        "Bogota",
        "Lima",
        "Santiago",
        "SaoPaulo",
        "BuenosAires",
        "Lagos",
        "Kinshasa",
        "Khartoum",
        "Johannesburg",

        "Moscow",
        "Tehran",
        "Delhi",
        "Kolkata",
        "Chennai",
        "Mumbai",
        "Karachi",
        "Baghdad",
        "Riyadh",
        "Cairo",
        "Algiers",
        "Istanbul",

        "SanFrancisco",
        "Chicago",
        "Montreal",
        "Atlanta",
        "NewYork",
        "Washington",
        "Madrid",
        "London",
        "Paris",
        "Essen",
        "Milan",
        "StPetersburg"
    };
}
