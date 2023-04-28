#pragma once

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <chrono>
#include <cstdlib>

using namespace std;

struct media {
    // function variables
    string referenceNumber;
    string mediaType;
    string englishName;
    string originalName;
    string adultContent;
    int releaseYear;
    string endYear;
    int runTime;
    string genres;

    // function declarations
    media();
    media(string _referenceNumber, string _mediaType, string _englishName, string _originalName,
          string _adultContent, int _releaseYear, string _endYear, int _runTime, string _genres);
};