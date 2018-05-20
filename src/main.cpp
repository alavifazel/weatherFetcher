#include "geolocation.h"
#include "include/rapidjson/document.h"
#include "include/rapidjson/writer.h"
#include "include/rapidjson/stringbuffer.h"
#include <fstream>
#include <string>

void printInfo(const double temperature, const double humidity, const std::string weatherCondition){
    std::cout << "Temperature: " << temperature - 273 << "°\n"; // Kelvin to celsius
    std::cout << "Humidity: " << humidity << "%\n";
    std::cout << "Condition:\n\n" << weatherCondition << '\n';
}

std::map<std::string,std::string> loadASCIIArt(std::array<std::string, 7> weatherCodenames){
    std::map<std::string, std::string> weatherConditions;
    for(const auto &i : weatherCodenames){
        std::string path = "../ascii-arts/";
        path += i + ".txt";
        std::ifstream ifs(path);
        std::stringstream buffer;
        buffer << ifs.rdbuf();
        weatherConditions[i] = buffer.str();
    }
    return weatherConditions;
}


int main(){
    std::string weatherToken = "<TOKEN>";
    // TODO : read it from database. right now they are hardcoded..
    std::array<std::string, 7> weatherCategories = {"Thunderstorm", "Clear", "Clouds", "Drizzle","Rain", "Snow", "Atmosphere"};
    std::map<int,std::string> weatherCodenames{{200, "Thunderstorm"},{201, "Thunderstorm"}, {202, "Thunderstorm"},{210, "Thunderstorm" },{211,"Thunderstorm" },{212,"Thunderstorm"},{221,"Thunderstorm"},{230, "Thunderstorm"},{231,"Thunderstorm"},{232,"Thunderstorm"},
                                     {800,"Clear"},
                                     {801,"Clouds"}, {802, "Clouds"}, {803, "Clouds"}, {804, "Clouds"},
                                     {300, "Drizzle"},{301,"Drizzle"}, {302,"Drizzle"}, {310,"Drizzle"},{311,"Drizzle"},{312,"Drizzle"},{313,"Drizzle"},{314,"Drizzle" }, {321,"Drizzle"},
                                     {500,"Rain"}, {501,"Rain"}, {502,"Rain"}, {503,"Rain"}, {504,"Rain"}, {511,"Rain"}, {520,"Rain"}, {521,"Rain"}, {522,"Rain"},{531,"Rain"},
                                     {600,"Snow"},{601,"Snow"},{602 ,"Snow"},{611,"Snow"},{612,"Snow"},{615,"Snow"},{616,"Snow"},{620,"Snow"},{621,"Snow"},{622, "Snow"},
                                     {701, "Atmosphere"},{711, "Atmosphere"},{721 , "Atmosphere"},{731 , "Atmosphere"},{741 , "Atmosphere"},{751, "Atmosphere"},{761 , "Atmosphere"},{762 , "Atmosphere"},{771 , "Atmosphere"},{781 , "Atmosphere"}};
    std::map<std::string, std::string> weatherConditions = loadASCIIArt(weatherCategories);
    auto f = [](http::response<http::string_body> c){ std::ofstream of("ipFetch.json"); of << c.body();};
    fetch_sync("ip-api.com","/json", f);
    std::ifstream i("ipFetch.json");
    std::stringstream buffer;
    buffer << i.rdbuf();
    rapidjson::Document d;
    d.Parse(buffer.str().c_str());

    std::string weatherDIR = "/data/2.5/weather?q=";
    weatherDIR += d["city"].GetString();
    weatherDIR += "&appid=";
    weatherDIR += weatherToken;
    fetch_sync("api.openweathermap.org", weatherDIR, [](http::response<http::string_body> c) {
        std::ofstream of("weather.json"); of << c.body();
    });

    std::ifstream i2("weather.json");
    std::stringstream buffer2;
    buffer2 << i2.rdbuf();
    rapidjson::Document d2;
    d2.Parse(buffer2.str().c_str());

    std::string weatherCondition;
    for(const auto &i : weatherCodenames){
        if(d2["weather"][0]["id"].GetInt() == i.first){
            weatherCondition = weatherConditions[i.second];
        }
    }
    printInfo(d2["main"]["temp"].GetDouble(), d2["main"]["humidity"].GetDouble(), weatherCondition);

}

