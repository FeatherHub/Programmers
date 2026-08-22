int[] solution(int[] arr)
{
    int[] stk = new int[arr.Length];
    int stkLastElemIdx = -1;

    int arrIdx = 0;
    while (arrIdx < arr.Length)
    {
        int arrElem = arr[arrIdx];
        if (stkLastElemIdx == -1)
        {
            stkLastElemIdx++;
            stk[stkLastElemIdx] = arrElem;
            arrIdx++;
        }
        else
        {
            int stkLastElem = stk[stkLastElemIdx];
            if (stkLastElem < arrElem)
            {
                stkLastElemIdx++;
                stk[stkLastElemIdx] = arrElem;
                arrIdx++;
            }
            else
            {
                stkLastElemIdx--;
            }
        }
    }

    return stk[..(stkLastElemIdx + 1)];
}