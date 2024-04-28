#include <bits/stdc++.h>
using namespace std;

int Q, S, E;
pair<int, string> album[] = {
{1967, "DavidBowie"},
{1969, "SpaceOddity"},
{1970, "TheManWhoSoldTheWorld"},
{1971, "HunkyDory"},
{1972, "TheRiseAndFallOfZiggyStardustAndTheSpidersFromMars"},
{1973, "AladdinSane"},
{1973, "PinUps"},
{1974, "DiamondDogs"},
{1975, "YoungAmericans"},
{1976, "StationToStation"},
{1977, "Low"},
{1977, "Heroes"},
{1979, "Lodger"},
{1980, "ScaryMonstersAndSuperCreeps"},
{1983, "LetsDance"},
{1984, "Tonight"},
{1987, "NeverLetMeDown"},
{1993, "BlackTieWhiteNoise"},
{1995, "1.Outside"},
{1997, "Earthling"},
{1999, "Hours"},
{2002, "Heathen"},
{2003, "Reality"},
{2013, "TheNextDay"},
{2016, "BlackStar"}
};

int main(void) {
    ios_base::sync_with_stdio(0); cout.tie(0); cin.tie(0);

    cin >> Q;

    while(Q--) {
        cin >> S >> E;

        int cnt = 0;
        for(auto i : album) {
            if(i.first >= S && i.first <= E) cnt++;
        }
        cout << cnt << '\n';

        for(auto i : album) {
            if(i.first >= S && i.first <= E) {
                cout << i.first << ' ' << i.second << '\n';
            }
        }
    }
}