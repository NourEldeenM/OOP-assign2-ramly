#include <bits/stdc++.h>

using namespace std;

int main()
{
    // making a list of 10 names and scores
    vector<pair<int, string>> v;
    for (int i = 0; i < 10; i++)
    {
        int x;
        string y;
        printf("Enter name and Score for player %d:\n", i+1);
        cin >> y >> x;
        v.push_back({x, y});
    }
    sort(v.rbegin(), v.rend());
    bool flag = true;
    while (flag)
    {
        cout << "which program do you want?\n"
                "a-\tAdd new player to the list\n"
                "b-\tPrint the top 10 names and scores to the screen\n"
                "c-\tEnter a player name to outbut his high score\n"
                "0-\tExit\n";
        char target;
        cin >> target;
        if (target == 'a')
        {
            // add the name of the player he want to add and its score by check if its score is bigger than the smallest scoore 
            cout << "Enter the name you want and his score:";
            int x;
            string y;
            cin >> y >> x;
            if (x > v.back().first)
            {
            // if the condition is true he will delete the player who had the smallest score and and the newest one
                v.pop_back();
                v.push_back({x, y});
                sort(v.rbegin(), v.rend());
            }
        }
        else if (target == 'b')
        {
            // print the players and their scores 
            for (auto it : v)
            {
                cout << it.second << " " << it.first << endl;
            }
        }
        else if (target == 'c')
        {
            // check if the name you are asked for is in the list or not and if he in the list print his highest score 
            bool check = false;
            cout << "Enter your target player name: ";
            string s;
            cin >> s;
            for (int i = 0; i < 10; i++)
            {
                if (v[i].second == s)
                {
                    cout << v[i].first << endl;
                    check = true;
                    break;
                }
            }
            if (!check)
            // if check equal false that mean the name is not in the list
                cout << "this player is not in the list\n";
        }
        else if (target == '0')
        // break
            flag = false;
    }
}
