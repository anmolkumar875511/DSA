// https://leetcode.com/problems/coupon-code-validator/description/
#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    vector<string> validateCoupons(vector<string>& code, vector<string>& businessLine, vector<bool>& isActive) {

        int n = code.size();
        vector<pair<string,string>> validCoupons;
        unordered_map <string, int> order = {
            {"electronics", 0},
            {"grocery", 1},
            {"pharmacy", 2},
            {"restaurant", 3}
        };

        for(int i = 0; i < n; i++){

            if(!(isActive[i])) continue;

            if(order.find(businessLine[i]) == order.end()) continue;

            if(code[i].empty()) continue;

            bool valid = true;
            for(auto ch : code[i]){
                if(!isalnum(ch) && ch != '_'){
                    valid = false;
                    break;
                }
            }

            if(valid){
                validCoupons.push_back({businessLine[i], code[i]});
            }
        }

            sort(validCoupons.begin(), validCoupons.end(),
            [&](const pair<string, string>& a, const pair<string, string>& b){
                if(order[a.first] != order[b.first]){
                    return order[a.first] < order[b.first];
                }
                return a.second < b.second;
            });

            vector<string> res;
            for(auto p : validCoupons){
                res.push_back(p.second);
            }

            return res;
    }
};


