#include <iostream>
using namespace std;

double Median(int A[], int m, int B[], int n)
{

    if (m > n)
    {
        return Median(B, n, A, m);
    }

    int low = 0;
    int high = m;

    while (low <= high)
    {
        int i = (low + high) / 2;
        int j = (m + n + 1) / 2 - i;

        int leftA, rightA, leftB, rightB;

        if (i == 0)
        {
            leftA = -1000000000;
        }
        else
        {
            leftA = A[i - 1];
        }

        if (i == m)
        {
            rightA = 1000000000;
        }
        else
        {
            rightA = A[i];
        }

        if (j == 0)
        {
            leftB = -1000000000;
        }
        else
        {
            leftB = B[j - 1];
        }

        if (j == n)
        {
            rightB = 1000000000;
        }
        else
        {
            rightB = B[j];
        }

        if (leftA <= rightB && leftB <= rightA)
        {
            if ((m + n) % 2 == 0)
            {
                int maxLeft;
                if (leftA > leftB)
                {
                    maxLeft = leftA;
                }
                else
                {
                    maxLeft = leftB;
                }

                int minRight;
                if (rightA < rightB)
                {
                    minRight = rightA;
                }
                else
                {
                    minRight = rightB;
                }

                return (maxLeft + minRight) / 2.0;
            }
            else
            {
                if (leftA > leftB)
                {
                    return leftA;
                }
                else
                {
                    return leftB;
                }
            }
        }
        else if (leftA > rightB)
        {
            high = i - 1;
        }
        else
        {
            low = i + 1;
        }
    }
    return 0.0;
}

int main()
{
    int m, n;
    cout << "Enter the size of first array: ";
    cin >> m;
    int nums1[m];
    cout << "Enter the elements for first array(in sorted): ";
    for (int i = 0; i < m; i++)
    {
        cin >> nums1[i];
    }

    cout << "Enter the size of second array: ";
    cin >> n;

    int nums2[n];

    cout << "Enter the elements for second array(in sorted): ";
    for (int i = 0; i < n; i++)
    {
        cin >> nums2[i];
    }

    double median = Median(nums1, m, nums2, n);
    cout << "Median: " << median << endl;

    return 0;
}

