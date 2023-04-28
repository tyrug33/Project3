#include "media.h"

// fully-defined object constructor
media::media(string _referenceNumber, string _mediaType, string _englishName, string _originalName,
             string _adultContent, int _releaseYear, string _endYear, int _runTime, string _genres) {
    referenceNumber = _referenceNumber;
    mediaType = _mediaType;
    englishName = _englishName;
    originalName = _originalName;
    adultContent = _adultContent;
    releaseYear = _releaseYear;
    endYear = _endYear;
    runTime = _runTime;
    genres = _genres;
}

// default constructor
media::media() {
    referenceNumber = "";
    mediaType = "";
    englishName = "";
    originalName = "";
    adultContent = "";
    releaseYear = 0;
    endYear = "";
    runTime = 0;
    genres = "";
}