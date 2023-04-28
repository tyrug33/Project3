#include "media.h"

// mergesort function declarations
void sortYear(vector<media>& main);
void mergeSortYear(vector<media>& left, vector<media>& right, vector<media>& main);
void sortRuntime(vector<media>& main);
void mergeSortRuntime(vector<media>& left, vector<media>& right, vector<media>& main);

// count sort function declaration
vector<media> countingSortYear(vector<media> &genre);
vector<media> countingSortRuntime(vector<media> &genre);

// mergesort function definitions
void sortYear(vector<media>& main) {
    // base case to exit recursion
    if (main.size() <= 1) {
        return;
    }

    // get the mid-point of the passed in vector by dividing it by 2
    int mid = main.size() / 2;

    // create the two temporary sub arrays to sort
    vector<media> left;
    vector<media> right;

    // pushes the first half of the passed in array to the first sub array
    for (int i = 0; i < mid; ++i) {
        left.push_back(main[i]);
    }

    // pushes the second half of the passed in array to the first sub array
    for (int i = 0; i < main.size() - mid; ++i) {
        right.push_back(main[mid + i]);
    }

    // recursive calls to sort the entire vector
    sortYear(left);
    sortYear(right);
    mergeSortYear(left, right, main);
}
void mergeSortYear(vector<media>& left, vector<media>& right, vector<media>& main) {
    // temp variable to get size of both passed in arrays
    int lSubArraySize = left.size();
    int rSubArraySize = right.size();

    // variables to keep track of the index of the sub arrays
    int iSubArrayR = 0;
    int iSubArrayL = 0;
    int iMergedArray = 0;

    // while loops to merge the two sub arrays into one array
    while (iSubArrayL < lSubArraySize && iMergedArray < rSubArraySize) {
        if (left[iSubArrayL].releaseYear < right[iMergedArray].releaseYear) {
            main[iSubArrayR] = left[iSubArrayL];
            iSubArrayL++;
        }
        else {
            main[iSubArrayR] = right[iMergedArray];
            iMergedArray++;
        }
        iSubArrayR++;
    }
    // copy the remaining elements of the left array if there are any
    while (iSubArrayL < lSubArraySize) {
        main[iSubArrayR] = left[iSubArrayL];
        iSubArrayL++;
        iSubArrayR++;
    }
    // copy the remaining elements of the right array if there are any
    while (iMergedArray < rSubArraySize) {
        main[iSubArrayR] = right[iMergedArray];
        iMergedArray++;
        iSubArrayR++;
    }
}
void sortRuntime(vector<media>& main) {
    // base case to exit recursion
    if (main.size() <= 1) {
        return;
    }

    // get the mid-point of the passed in vector by dividing it by 2
    int mid = main.size() / 2;

    // create the two temporary sub arrays to sort
    vector<media> left;
    vector<media> right;

    // pushes the first half of the passed in array to the first sub array
    for (int i = 0; i < mid; ++i) {
        left.push_back(main[i]);
    }

    // pushes the second half of the passed in array to the first sub array
    for (int i = 0; i < main.size() - mid; ++i) {
        right.push_back(main[mid + i]);
    }

    // recursive calls to sort the entire vector
    sortRuntime(left);
    sortRuntime(right);
    mergeSortRuntime(left, right, main);
}
void mergeSortRuntime(vector<media>& left, vector<media>& right, vector<media>& main) {
    // temp variable to get size of both passed in arrays
    int lSubArraySize = left.size();
    int rSubArraySize = right.size();

    // variables to keep track of the index of the sub arrays
    int iSubArrayR = 0;
    int iSubArrayL = 0;
    int iMergedArray = 0;

    // while loops to merge the two sub arrays into one array
    while (iSubArrayL < lSubArraySize && iMergedArray < rSubArraySize) {
        if (left[iSubArrayL].runTime < right[iMergedArray].runTime) {
            main[iSubArrayR] = left[iSubArrayL];
            iSubArrayL++;
        }
        else {
            main[iSubArrayR] = right[iMergedArray];
            iMergedArray++;
        }
        iSubArrayR++;
    }
    // copy the remaining elements of the left array if there are any
    while (iSubArrayL < lSubArraySize) {
        main[iSubArrayR] = left[iSubArrayL];
        iSubArrayL++;
        iSubArrayR++;
    }
    // copy the remaining elements of the right array if there are any
    while (iMergedArray < rSubArraySize) {
        main[iSubArrayR] = right[iMergedArray];
        iMergedArray++;
        iSubArrayR++;
    }
}

//count sort function definitions
vector<media> countingSortYear(vector<media> &genre) {
    int n = genre.size();

    int maxYear = 0;
    int minYear = 0;

    for (int i = 1; i < n; i++) {
        if (genre[i].releaseYear > maxYear) {
            maxYear = genre[i].releaseYear;
        }
        if (genre[i].releaseYear < minYear) {
            minYear = genre[i].releaseYear;
        }
    }

    vector<int> count(maxYear - minYear + 1, 0);
    for (int i = 0; i < n; i++) {
        count[genre[i].releaseYear - minYear]++;
    }
    for (int i = 1; i < count.size(); i++) {
        count[i] += count[i - 1];
    }

    vector<media> sorted(n);
    for (int i = n - 1; i >= 0; i--) {
        sorted[count[genre[i].releaseYear - minYear] - 1] = genre[i];
        count[genre[i].releaseYear - minYear]--;
    }
    return sorted;
}
vector<media> countingSortRuntime(vector<media> &genre) {
    int n = genre.size();
    int maxTime = 0;
    int minTime = 0;

    for (int i = 1; i < n; i++) {
        if (genre[i].runTime > maxTime) {
            maxTime = genre[i].runTime;
        }
        if (genre[i].runTime < minTime) {
            minTime = genre[i].runTime;
        }
    }

    vector<int> count(maxTime - minTime + 1, 0);
    for (int i = 0; i < n; i++) {
        count[genre[i].runTime - minTime]++;
    }
    for (int i = 1; i < count.size(); i++) {
        count[i] += count[i - 1];
    }

    vector<media> sorted(n);
    for (int i = n - 1; i >= 0; i--) {
        sorted[count[genre[i].runTime - minTime] - 1] = genre[i];
        count[genre[i].runTime - minTime]--;
    }
    return sorted;
}

 int main() {
     // string of each genre used when finding where to put each movie object
     string action = "Action";
     string adventure = "Adventure";
     string comedy = "Comedy";
     string crime = "Crime";
     string documentary = "Documentary";
     string drama = "Drama";
     string family = "Family";
     string horror = "Horror";
     string sciFi = "Sci-Fi";

     // vectors of movies that are organized by genre
     vector<media> actions;
     vector<media> adventures;
     vector<media> comedies;
     vector<media> crimes;
     vector<media> documentaries;
     vector<media> dramas;
     vector<media> families;
     vector<media> horrors;
     vector<media> sciFis;

     // opening the file
     ifstream file("/Users/tyleredwards/CLionProjects/Project3/finaldatasetproject3final copy.tsv");

     // reading in the file
     if (file.is_open()) {
         // 1. read heading data from file to ignore it
         string lineFromFile;
         getline(file, lineFromFile);

         // while loop that reads in lines as long as there are lines to read
         while (getline(file, lineFromFile)) {
             istringstream stream(lineFromFile);

             // all the variables that need to be read in from the IMDB documentation
             string referenceNumber;
             string mediaType;
             string englishName;
             string originalName;
             string adultContent;
             int releaseYear;
             string endYear;
             int runTime;
             string genres;

             // two temp string variables to read in the integers
             string tempReleaseYear;
             string tempRunTime;

             // reading in all the values separated by tabs in this .tsv file and using stoi for the integers
             getline(stream, referenceNumber, '\t');
             getline(stream, mediaType, '\t');
             getline(stream, englishName, '\t');
             getline(stream, originalName, '\t');
             getline(stream, adultContent, '\t');
             getline(stream, tempReleaseYear, '\t');
             releaseYear = stoi(tempReleaseYear);
             getline(stream, endYear, '\t');
             getline(stream, tempRunTime, '\t');
             runTime = stoi(tempRunTime);
             getline(stream, genres, '\t');

             // create movie object based on read in information
             media set1 = media(referenceNumber, mediaType, englishName, originalName,
                                adultContent, releaseYear, endYear, runTime, genres);

             // series of if statements to see which genre vectors to put movie in
             // finds out if the keyword for each media type is in the genre string in the object
             if (set1.genres.find(action) != string::npos) {
                 actions.push_back(set1);
             }
             if (set1.genres.find(adventure) != string::npos) {
                 adventures.push_back(set1);
             }
             if (set1.genres.find(comedy) != string::npos) {
                 comedies.push_back(set1);
             }
             if (set1.genres.find(crime) != string::npos) {
                 crimes.push_back(set1);
             }
             if (set1.genres.find(documentary) != string::npos) {
                 documentaries.push_back(set1);
             }
             if (set1.genres.find(drama) != string::npos) {
                 dramas.push_back(set1);
             }
             if (set1.genres.find(family) != string::npos) {
                 families.push_back(set1);
             }
             if (set1.genres.find(horror) != string::npos) {
                 horrors.push_back(set1);
             }
             if (set1.genres.find(sciFi) != string::npos) {
                 sciFis.push_back(set1);
             }
         }
         // close the file and the loop breaks
         file.close();
     }

     // while loop for main program to run in, will run until run is changed to 'x'
     char run = ' ';
     while (run != 'x') {
         // variables for user input
         int genreOption = 0;
         int yearOption = 0;
         int runtimeOption = 0;

         // final vectors that will be printed for each type of sort
         // merge sort vector
         vector<media> mChosenGenre;
         // count sort vector
         vector<media> cChosenGenre;

         // get variables to keep time so that they are in the right scope
         auto startTime = chrono::high_resolution_clock::now();

         auto stopTime = chrono::high_resolution_clock::now();

         auto mTotalTime = chrono::duration_cast<chrono::microseconds>(stopTime - startTime);

         auto cTotalTime = chrono::duration_cast<chrono::microseconds>(stopTime - startTime);

         // start UI, reads in genre preference
         cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
         cout << "~~~~~~~~~~~~~~~~~~                    ~~~~~~~~~~~~~~~~~~" << endl;
         cout << "~~~~~~~~~~~~                                ~~~~~~~~~~~~" << endl;
         cout << "~~~~~~~                                          ~~~~~~~" << endl;
         cout << "~~~~~             Welcome to ScreenRecs!           ~~~~~" << endl;
         cout << "~~~~~~~                                          ~~~~~~~" << endl;
         cout << "~~~~~~~~~~~~                                ~~~~~~~~~~~~" << endl;
         cout << "~~~~~~~~~~~~~~~~~~                    ~~~~~~~~~~~~~~~~~~" << endl;
         cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
         cout << endl;
         cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
         cout << "~~~~                 Select a genre                 ~~~~" << endl;
         cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
         cout << "~~~~      1 Adventure  2 Action       3 Family      ~~~~" << endl;
         cout << "~~~~      4 Comedy     5 Drama        6 Horror      ~~~~" << endl;
         cout << "~~~~      7 Sci-Fi     8 Documentary  9 Crime       ~~~~" << endl;
         cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
         cout << "~~~~" << endl;
         cout << " ";
         cin >> genreOption;
         cout << "~~~~" << endl;

         // switch statement to choose which genre vector to load into created vectors
         switch (genreOption) {
             case 1: {
                 mChosenGenre = actions;
                 cChosenGenre = actions;
                 break;
             }
             case 2: {
                 mChosenGenre = adventures;
                 cChosenGenre = adventures;
                 break;
             }
             case 3: {
                 mChosenGenre = comedies;
                 cChosenGenre = comedies;
                 break;
             }
             case 4: {
                 mChosenGenre = crimes;
                 cChosenGenre = crimes;
                 break;
             }
             case 5: {
                 mChosenGenre = documentaries;
                 cChosenGenre = documentaries;
                 break;
             }
             case 6: {
                 mChosenGenre = dramas;
                 cChosenGenre = dramas;
                 break;
             }
             case 7: {
                 mChosenGenre = families;
                 cChosenGenre = families;
                 break;
             }
             case 8: {
                 mChosenGenre = horrors;
                 cChosenGenre = horrors;
                 break;
             }
             case 9: {
                 mChosenGenre = sciFis;
                 cChosenGenre = sciFis;
                 break;
             }
             // if input is not in range 1-9, quits program from running
             default: {
                 cout << "Invalid input" << endl;
                 run = 'x';
             }
         }

         // continue menu here, reads in release year preference
         cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
         cout << "~~~~      Select the range for year of release      ~~~~" << endl;
         cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
         cout << "~~~~            1 2005-2009  2 2010-2014            ~~~~" << endl;
         cout << "~~~~            3 2015-2019  4 2020-2023            ~~~~" << endl;
         cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
         cout << "~~~~" << endl;
         cout << " ";
         cin >> yearOption;
         cout << "~~~~" << endl;

         // only take the movies in the specific year range
         switch (yearOption) {
             case 1: {
                 // merge sort
                 // start the clock
                 startTime = chrono::high_resolution_clock::now();

                 // call the sort function to sort the vector by year of release
                 sortYear(mChosenGenre);

                 // end the clock
                 stopTime = chrono::high_resolution_clock::now();

                 // add the time this took to the total time for the merge sort function to run
                 mTotalTime += chrono::duration_cast<chrono::microseconds>(stopTime - startTime);

                 // temporary empty vector to push values into
                 vector<media> tempMerge;

                 // pushes values in first range into temp vector
                 for (int i = 0; i < mChosenGenre.size(); ++i) {
                     if (mChosenGenre[i].releaseYear >= 2005 && mChosenGenre[i].releaseYear <= 2009) {
                         tempMerge.push_back(mChosenGenre[i]);
                     }
                 }
                 // overrides the main vector equal to the temp vector
                 mChosenGenre = tempMerge;

                 // count sort
                 startTime = chrono::high_resolution_clock::now();

                 // saves the returned vector of countingSortYear to new vector called sortedByYear
                 vector<media> sortedByYear(countingSortYear(cChosenGenre));

                 stopTime = chrono::high_resolution_clock::now();

                 cTotalTime += chrono::duration_cast<chrono::microseconds>(stopTime - startTime);

                 //push media that's within year range into tempCount
                 vector<media> tempCount;
                 //look through sorted by year for movies that fit the chosen yearOption
                 for (int i = 0; i < sortedByYear.size(); ++i) {
                     if (sortedByYear[i].releaseYear >= 2005 && sortedByYear[i].releaseYear <= 2009) {
                         tempCount.push_back(sortedByYear[i]);
                     }
                 }
                 cChosenGenre = tempCount;
                 break;
             }
             case 2: {
                 // merge sort
                 startTime = chrono::high_resolution_clock::now();

                 // call the sort function to sort the vector by year of release
                 sortYear(mChosenGenre);

                 stopTime = chrono::high_resolution_clock::now();

                 // call the sort function to sort the vector by year of release
                 mTotalTime += chrono::duration_cast<chrono::microseconds>(stopTime - startTime);

                 vector<media> tempMerge;

                 // pushes values in second range into temp vector
                 for (int i = 0; i < mChosenGenre.size(); ++i) {
                     if (mChosenGenre[i].releaseYear >= 2010 && mChosenGenre[i].releaseYear <= 2014) {
                         tempMerge.push_back(mChosenGenre[i]);
                     }
                 }
                 // overrides the main vector equal to the temp vector
                 mChosenGenre = tempMerge;

                 // count sort
                 startTime = chrono::high_resolution_clock::now();

                 // saves the returned vecotr of countingSortYear to new vector called sortedByYear
                 vector<media> sortedByYear(countingSortYear(cChosenGenre));

                 stopTime = chrono::high_resolution_clock::now();

                 cTotalTime += chrono::duration_cast<chrono::microseconds>(stopTime - startTime);
                 //push media that's within year range into tempCount
                 vector<media> tempCount;
                 //look through sorted by year for movies that fit the chosen yearOption
                 for (int i = 0; i < sortedByYear.size(); ++i) {
                     if (sortedByYear[i].releaseYear >= 2010 && sortedByYear[i].releaseYear <= 2014) {
                         tempCount.push_back(sortedByYear[i]);
                     }
                 }
                 cChosenGenre = tempCount;
                 break;
             }
             case 3: {
                 // merge sort
                 startTime = chrono::high_resolution_clock::now();

                 // call the sort function to sort the vector by year of release
                 sortYear(mChosenGenre);

                 stopTime = chrono::high_resolution_clock::now();

                 // add the time this took to the total time for the merge sort function to run
                 mTotalTime += chrono::duration_cast<chrono::microseconds>(stopTime - startTime);

                 vector<media> tempMerge;

                 // pushes values in third range into temp vector
                 for (int i = 0; i < mChosenGenre.size(); ++i) {
                     if (mChosenGenre[i].releaseYear >= 2015 && mChosenGenre[i].releaseYear <= 2019) {
                         tempMerge.push_back(mChosenGenre[i]);
                     }
                 }
                 // overrides the main vector equal to the temp vector
                 mChosenGenre = tempMerge;

                 // count sort
                 startTime = chrono::high_resolution_clock::now();

                 // saves the returned vector of countingSortYear to new vector called sortedByYear
                 vector<media> sortedByYear(countingSortYear(cChosenGenre));

                 stopTime = chrono::high_resolution_clock::now();

                 cTotalTime += chrono::duration_cast<chrono::microseconds>(stopTime - startTime);
                 //push media that's within year range into tempCount
                 vector<media> tempCount;
                 //look through sorted by year for movies that fit the chosen yearOption
                 for (int i = 0; i < sortedByYear.size(); ++i) {
                     if (sortedByYear[i].releaseYear >= 2015 && sortedByYear[i].releaseYear <= 2019) {
                         tempCount.push_back(sortedByYear[i]);
                     }
                 }
                 cChosenGenre = tempCount;
                 break;
             }
             case 4: {
                 // merge sort
                 startTime = chrono::high_resolution_clock::now();

                 // call the sort function to sort the vector by year of release
                 sortYear(mChosenGenre);

                 stopTime = chrono::high_resolution_clock::now();

                 // add the time this took to the total time for the merge sort function to run
                 mTotalTime += chrono::duration_cast<chrono::microseconds>(stopTime - startTime);

                 vector<media> tempMerge;

                 // pushes values in fourth range into temp vector
                 for (int i = 0; i < mChosenGenre.size(); ++i) {
                     if (mChosenGenre[i].releaseYear >= 2020 && mChosenGenre[i].releaseYear <= 2023) {
                         tempMerge.push_back(mChosenGenre[i]);
                     }
                 }
                 // overrides the main vector equal to the temp vector
                 mChosenGenre = tempMerge;

                 // count sort
                 startTime = chrono::high_resolution_clock::now();

                 // saves the returned vector of countingSortYear to new vector called sortedByYear
                 vector<media> sortedByYear(countingSortYear(cChosenGenre));

                 stopTime = chrono::high_resolution_clock::now();

                 cTotalTime += chrono::duration_cast<chrono::microseconds>(stopTime - startTime);
                 //push media that's within year range into tempCount
                 vector<media> tempCount;
                 //look through sorted by year for movies that fit the chosen yearOption
                 for (int i = 0; i < sortedByYear.size(); ++i) {
                     if (sortedByYear[i].releaseYear >= 2020 && sortedByYear[i].releaseYear <= 2023) {
                         tempCount.push_back(sortedByYear[i]);
                     }
                 }
                 cChosenGenre = tempCount;
                 break;
             }
             // if input is not in range 1-9, quits program from running
             default: {
                 cout << "Invalid input" << endl;
                 run = 'x';
             }
         }

         // continue menu here, reads in runtime preference
         cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
         cout << "~~~~              Select media runtime              ~~~~" << endl;
         cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
         cout << "~~~~            1 1-30 min   2 30-60 min            ~~~~" << endl;
         cout << "~~~~            3 60-90 min  4 90-240 min           ~~~~" << endl;
         cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
         cout << "~~~~" << endl;
         cout << " ";
         cin >> runtimeOption;
         cout << "~~~~" << endl;

         // only take the movies in the specific runtime range
         switch (runtimeOption) {
             case 1: {
                 // merge sort
                 startTime = chrono::high_resolution_clock::now();

                 // call the sort function to sort the vector by runtime
                 sortRuntime(mChosenGenre);

                 stopTime = chrono::high_resolution_clock::now();

                 // add the time this took to the total time for the merge sort function to run
                 mTotalTime += chrono::duration_cast<chrono::microseconds>(stopTime - startTime);

                 vector<media> tempMerge;

                 // pushes values in first runtime range into temp vector
                 for (int i = 0; i < mChosenGenre.size(); ++i) {
                     if (mChosenGenre[i].runTime >= 1 && mChosenGenre[i].runTime <= 30) {
                         tempMerge.push_back(mChosenGenre[i]);
                     }
                 }
                 mChosenGenre = tempMerge;

                 // count sort
                 startTime = chrono::high_resolution_clock::now();

                 // saves the returned vector of countingSortRuntime to new vector called sortedByRuntime
                 vector<media> sortedByRuntime(countingSortRuntime(cChosenGenre));

                 stopTime = chrono::high_resolution_clock::now();

                 cTotalTime += chrono::duration_cast<chrono::microseconds>(stopTime - startTime);

                 //push media that's within runtime range into tempCount
                 vector<media> tempCount;
                 //look through sorted by runtime for movies that fit the chosen runtimeOption
                 for (int i = 0; i < sortedByRuntime.size(); ++i) {
                     if (sortedByRuntime[i].runTime >= 1 && sortedByRuntime[i].runTime <= 30) {
                         tempCount.push_back(sortedByRuntime[i]);
                     }
                 }
                 cChosenGenre = tempCount;
                 break;
             }
             case 2: {
                 // merge sort
                 startTime = chrono::high_resolution_clock::now();

                 // call the sort function to sort the vector by runtime
                 sortRuntime(mChosenGenre);

                 stopTime = chrono::high_resolution_clock::now();

                 // add the time this took to the total time for the merge sort function to run
                 mTotalTime += chrono::duration_cast<chrono::microseconds>(stopTime - startTime);

                 vector<media> tempMerge;

                 // pushes values in second runtime range into temp vector
                 for (int i = 0; i < mChosenGenre.size(); ++i) {
                     if (mChosenGenre[i].runTime >= 31 && mChosenGenre[i].runTime <= 60) {
                         tempMerge.push_back(mChosenGenre[i]);
                     }
                 }
                 mChosenGenre = tempMerge;

                 // count sort
                 startTime = chrono::high_resolution_clock::now();

                 // saves the returned vect of countingSortRuntime to new vect called sortedByRuntime
                 vector<media> sortedByRuntime(countingSortRuntime(cChosenGenre));

                 stopTime = chrono::high_resolution_clock::now();

                 cTotalTime += chrono::duration_cast<chrono::microseconds>(stopTime - startTime);

                 //push media thats within runtime range into tempCount
                 vector<media> tempCount;
                 //look through sorted by runtime for movies that fit the chosen runtimeOption
                 for (int i = 0; i < sortedByRuntime.size(); ++i) {
                     if (sortedByRuntime[i].runTime >= 31 && sortedByRuntime[i].runTime <= 60) {
                         tempCount.push_back(sortedByRuntime[i]);
                     }
                 }
                 cChosenGenre = tempCount;
                 break;
             }
             case 3: {
                 // merge sort
                 startTime = chrono::high_resolution_clock::now();

                 // call the sort function to sort the vector by runtime
                 sortRuntime(mChosenGenre);

                 stopTime = chrono::high_resolution_clock::now();

                 // add the time this took to the total time for the merge sort function to run
                 mTotalTime += chrono::duration_cast<chrono::microseconds>(stopTime - startTime);

                 vector<media> tempMerge;

                 // pushes values in third runtime range into temp vector
                 for (int i = 0; i < mChosenGenre.size(); ++i) {
                     if (mChosenGenre[i].runTime >= 61 && mChosenGenre[i].runTime <= 90) {
                         tempMerge.push_back(mChosenGenre[i]);
                     }
                 }
                 mChosenGenre = tempMerge;

                 // count sort
                 startTime = chrono::high_resolution_clock::now();

                 // saves the returned vect of countingSortRuntime to new vect called sortedByRuntime
                 vector<media> sortedByRuntime(countingSortRuntime(cChosenGenre));

                 stopTime = chrono::high_resolution_clock::now();

                 cTotalTime += chrono::duration_cast<chrono::microseconds>(stopTime - startTime);

                 //push media that's within runtime range into tempCount
                 vector<media> tempCount;
                 //look through sorted by runtime for movies that fit the chosen runtimeOption
                 for (int i = 0; i < sortedByRuntime.size(); ++i) {
                     if (sortedByRuntime[i].runTime >= 61 && sortedByRuntime[i].runTime <= 90) {
                         tempCount.push_back(sortedByRuntime[i]);
                     }
                 }
                 cChosenGenre = tempCount;
                 break;
             }
             case 4: {
                 // merge sort
                 startTime = chrono::high_resolution_clock::now();

                 // call the sort function to sort the vector by runtime
                 sortRuntime(mChosenGenre);

                 stopTime = chrono::high_resolution_clock::now();

                 // add the time this took to the total time for the merge sort function to run
                 mTotalTime += chrono::duration_cast<chrono::microseconds>(stopTime - startTime);

                 vector<media> tempMerge;

                 // pushes values in fourth runtime range into temp vector
                 for (int i = 0; i < mChosenGenre.size(); ++i) {
                     if (mChosenGenre[i].runTime >= 91 && mChosenGenre[i].runTime <= 240) {
                         tempMerge.push_back(mChosenGenre[i]);
                     }
                 }
                 mChosenGenre = tempMerge;

                 // count sort
                 startTime = chrono::high_resolution_clock::now();

                 // saves the returned vector of countingSortRuntime to new vector called sortedByRuntime
                 vector<media> sortedByRuntime(countingSortRuntime(cChosenGenre));

                 stopTime = chrono::high_resolution_clock::now();

                 cTotalTime += chrono::duration_cast<chrono::microseconds>(stopTime - startTime);

                 //push media that's within runtime range into tempCount
                 vector<media> tempCount;
                 //look through sorted by runtime for movies that fit the chosen runtimeOption
                 for (int i = 0; i < sortedByRuntime.size(); ++i) {
                     if (sortedByRuntime[i].runTime >= 91 && sortedByRuntime[i].runTime <= 240) {
                         tempCount.push_back(sortedByRuntime[i]);
                     }
                 }
                 cChosenGenre = tempCount;
                 break;
             }
             // if input is not in range 1-9, quits program from running
             default: {
                 cout << "Invalid input" << endl;
                 run = 'x';
             }
         }

         // get the index for 3 randomly spaced recommendations
         // get a seed
         srand((unsigned) time(NULL));

         // create 3 randomly generated indexes inside the range of the final vector
         int indexFirstMedia = rand() % cChosenGenre.size();
         int indexSecondMedia = rand() % cChosenGenre.size();
         int indexThirdMedia = rand() % cChosenGenre.size();

         // continue menu here, prints out recommendations
         cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
         cout << "~~~~             Top 3 recommended media            ~~~~" << endl;
         cout << "~~~~             based on your criteria             ~~~~" << endl;
         cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
         cout << cChosenGenre[indexFirstMedia].englishName << ", "
              << cChosenGenre[indexFirstMedia].releaseYear << ", "
              << cChosenGenre[indexFirstMedia].runTime << " min" << endl;

         cout << cChosenGenre[indexSecondMedia].englishName << ", "
              << cChosenGenre[indexSecondMedia].releaseYear << ", "
              << cChosenGenre[indexSecondMedia].runTime << " min" << endl;

         cout << cChosenGenre[indexThirdMedia].englishName << ", "
              << cChosenGenre[indexThirdMedia].releaseYear << ", "
              << cChosenGenre[indexThirdMedia].runTime << " min" << endl;
         cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
         cout << endl;

         // compares the times that merge sort and counting sort took to both sort the same vector twice
         cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
         cout << "~~~~    Total counting sort and merge sort times    ~~~~" << endl;
         cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
         cout << "~~~~  Counting: " << cTotalTime.count() << " microseconds" << endl;
         cout << "~~~~  Merge: " << mTotalTime.count() << " microseconds" << endl;
         cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
         if (cTotalTime.count() < mTotalTime.count()) {
             cout << "~~   Counting sort performed faster than merge sort   ~~" << endl;
         } else {
             cout << "~~   Merge sort performed faster than counting sort   ~~" << endl;
         }
         cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
         cout << endl;

         // escape sequence for the while loop that loops the program
         cout << "Enter x to exit. Press any other key to continue." << endl;
         cin >> run;
     }
 }