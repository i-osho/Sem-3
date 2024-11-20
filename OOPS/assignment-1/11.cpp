// Program to count ballot papers
#include <iostream>
using namespace std;

int main()
{
    int count[5] = {0};
    int spoiltBallots = 0;
    int nVotes, vote;

    cout << "Enter the number of ballots: ";
    cin >> nVotes;

    for (int i = 0; i < nVotes; ++i)
    {
        cout << "Enter vote for ballot " << i + 1 << ": ";
        cin >> vote;

        if (vote >= 1 && vote <= 5)
        {
            count[vote - 1]++;
        }
        else
        {
            spoiltBallots++;
        }
    }

    for (int i = 0; i < 5; ++i)
    {
        cout << "Candidate " << i + 1 << " received " << count[i] << " votes" << endl;
    }
    cout << "Number of spoilt ballots: " << spoiltBallots;

    return 0;
}
