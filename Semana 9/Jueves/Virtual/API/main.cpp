#include <iostream>
#include "HttpClient.h"
#include "json.hpp"
#include "Fruta.h"
using namespace std;

int main()
{
    HttpClient client;
    nlohmann::json data;
    Fruta *frutas;
    int cantidad;
    
    string response = client.get("https://www.fruityvice.com/api/fruit/all");
    data = nlohmann::json::parse(response);
    
    cantidad = data.size();
    
    frutas = new Fruta[cantidad];
    
    for(int i=0; i<cantidad; i++){
        frutas[i] = Fruta(data[i]);
    }
    
    for(int i=0; i<cantidad ; i++){
      cout << frutas[i].toCSV() << endl;    
    }
    
    
    return 0;
}
