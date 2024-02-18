#include<bits/stdc++.h>

using namespace std;

//Define the structs Workshops and Available_Workshops.
//Implement the functions initialize and CalculateMaxWorkshops


struct Workshop {
    int start_time;
    int duration;
    int end_time;
};

struct Available_Workshops {
    int n;
    vector<Workshop> wsp;
};

bool operator<(const Workshop& a, const Workshop& b)
{
    return (a.end_time < b.end_time);
}

Available_Workshops* initialize(int start_time[], int duration[], int n)
{
    Available_Workshops* obj;
    obj = new Available_Workshops;
    obj->n = n;
    for(int i = 0; i < n; ++i)
    {
        obj->wsp.push_back((Workshop){start_time[i], duration[i], (start_time[i] + duration[i])});
    }
    return obj;
}

int CalculateMaxWorkshops(Available_Workshops* ptr)
{
    int MaxWorkshops = 0;
    int curr_end = -1;
    
    sort(ptr->wsp.begin(), ptr->wsp.end());
    for(int i = 0; i < ptr->n; ++i)
    {
        if (curr_end <= ptr->wsp[i].start_time)
        {
            curr_end = ptr->wsp[i].end_time;
            MaxWorkshops++;
        }
    }
    
    return MaxWorkshops;
}


int main(int argc, char *argv[]) {
    int n; // number of workshops
    cin >> n;
    // create arrays of unknown size n
    int* start_time = new int[n];
    int* duration = new int[n];

    for(int i=0; i < n; i++){
        cin >> start_time[i];
    }
    for(int i = 0; i < n; i++){
        cin >> duration[i];
    }

    Available_Workshops * ptr;
    ptr = initialize(start_time,duration, n);
    cout << CalculateMaxWorkshops(ptr) << endl;
    return 0;
}
