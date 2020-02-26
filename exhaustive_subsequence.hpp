///////////////////////////////////////////////////////////////////////////////
// exhaustive_subsequence.hpp
//
// Exhaustive search algorithms for the longest substring, and longest
// subsequence, problems.
//
///////////////////////////////////////////////////////////////////////////////

#pragma once

#include <algorithm>
#include <cstdint>
#include <random>
#include <string>
#include <cmath>   //Added for pow() function 2^n
#include <vector> //Added for Subsets() function

using namespace std;

std::vector<string> subsets(string s);

std::string exhaustive_longest_substring(const std::string& a,
  const std::string& b) {

    std::string substring = "";
    std::string best = "";

    for(int i = 0; i < a.length(); i++) {

      for(int j = 1; j <= a.length() - i; j++){

        substring = a.substr(i, j); //all substring instances in string 'a'

        if(b.find(substring) != std::string::npos && (substring.length() > best.length())){

          best = substring;
        }

      }//END Inner-Loop

    }//END Outer-Loop

    return best;

  }

  std::string random_letter_string(int seed, int size, int distinct_letters) {

    assert(size >= 0);
    assert(distinct_letters > 0);
    assert(distinct_letters <= 26);

    std::string s;

    std::mt19937 gen(seed);
    std::uniform_int_distribution<> dist('a', 'a' + distinct_letters - 1);

    for (int i = 0; i < size; ++i) {
      char ch;
      do {
        ch = dist(gen);
      } while (!isprint(ch));

      s.push_back(ch);
    }

    return s;
  }

  bool detect_subsequence(const std::string& candidate_subsequence,
    const std::string& candidate_supersequence) {

      int counter = 0;
      int loopCounter = 0;

      for(int i = 0; i < candidate_subsequence.length(); i++){

        for(int j = loopCounter; j < candidate_supersequence.length(); j++) {

          if(candidate_subsequence[i] == candidate_supersequence[j]) {

            counter++;
            loopCounter = j + 1;
            break;

          }

        }//END Inner-Loop

      }//END Outer-Loop
      

      //Return True if subsequence exists
      if(counter == candidate_subsequence.length()) {
        return true;
      }
      return false;
    }

    std::string exhaustive_longest_subsequence(const std::string& a,
      const std::string& b) {

        std::string candidateSubset = "";
        std::string shorter = "";
        std::string longer = "";
        std::string best = "";
        std::vector<string> candidate;

        if(a.length() > b.length()) {
          longer = a;
          shorter = b;
        } else {
          shorter = a;
          longer = b;
        }

        candidate = subsets(shorter);

        for(int index = 0; index < candidate.size(); index++){

          if(detect_subsequence(candidate[index], longer) == true && candidate[index].length() > best.length()) {
            best = candidate[index];

          }

        }//END For Loop

        return best;
      }


      std::vector<string> subsets(string s) {

        std::vector<string> elements;
        std::vector<string> vector;

        int n = pow(2, s.length());         // (2 ** n) evaluates to 2 to the n power

        std::string stringValue = "";



        for(int index = 0; index < s.length(); index++) {

          stringValue = s[index];

          elements.push_back(stringValue);

        }


        for(int i = 0; i < n; i++) {

          std::string sub = "";

          for(int j = 0; j < s.length(); j++) {

            if(((i >> j) & 1) == 1) {   //produces a Boolean True when bit j of i is 1.

              sub = sub + elements[j];

            }

          }//END Inner-Loop

          vector.push_back(sub);

        }//END Outer-Loop

        return vector;


      }
