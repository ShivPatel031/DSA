// Bubble Sort

vector<int> Bubble_sort(vector<int> array)
{

    bool check = true;

    for (int i = 0; i < array.size() - 1; i++)
    {
        for (int j = 0; j < array.size() - 1 - i; j++)
        {
            if (array[j] > array[j + 1])
            {

                int temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;

                check = false;
            }
        }

        if (check)
        {
            break;
        }
    }

    return array;
}
