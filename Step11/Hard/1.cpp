#include<iostream>
#include<vector>
#include<queue>
#include<unordered_map>
#include<unordered_set>
using namespace std;

class Twitter {
private:
    int time = 0;
    unordered_map<int, unordered_set<int>> follows;
    unordered_map<int, unordered_set<int>> tweets;
    unordered_map<int, int> posted_at;

public:
    Twitter() {
    }
    
    void postTweet(int userId, int tweetId) {
        tweets[userId].insert(tweetId);
        posted_at[tweetId] = time;
        time++;
    }
    
    vector<int> getNewsFeed(int userId) {
        priority_queue<pair<int, int>> pq;
        unordered_set<int> follows_list = follows[userId];
        follows_list.insert(userId);
        for(int follow : follows_list) {
            for(int tweetId : tweets[follow]) {
                pq.push({posted_at[tweetId], tweetId});
            }
        }
        vector<int> feed;
        int top_ten = 10;
        while(top_ten-- && !pq.empty()) {
            pair<int, int> tweet = pq.top();
            pq.pop();
            feed.push_back(tweet.second);
        }
        return feed;
    }
    
    void follow(int followerId, int followeeId) {
        follows[followerId].insert(followeeId);
        time++;
    }
    
    void unfollow(int followerId, int followeeId) {
        follows[followerId].erase(followeeId);
        time++;
    }
};


int main() {
    Twitter twitter;
    twitter.postTweet(1, 5);
    twitter.follow(1, 2);
    twitter.follow(2, 1);
    twitter.getNewsFeed(1);
    twitter.unfollow(1, 2);
    twitter.getNewsFeed(1);
    return 0;
}