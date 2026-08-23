using System;
using System.Collections.Generic;
using System.Linq;

public class Solution
{
    private readonly record struct DiceResultsAnalysis(int MostFrequentValue, int MostFrequentValueFrequency, List<int> OtherValues);

    public int solution(int a, int b, int c, int d)
    {
        int[] diceResults = [a, b, c, d];

        (int mostFrequentValue, int frequency) = GetMostFrequentValue(diceResults);

        DiceResultsAnalysis analysis = AnalyzeDiceResults(diceResults, mostFrequentValue, frequency);

        return ApplyScoreRule(analysis);
    }

    private static (int value, int frequency) GetMostFrequentValue(int[] array)
    {
        int mostFrequentValue = 0;
        int maxFrequency = 0;

        foreach (int targetValue in array)
        {
            int frequency = array.Count(value => targetValue == value);

            if (frequency > maxFrequency)
            {
                maxFrequency = frequency;
                mostFrequentValue = targetValue;
            }
        }

        return (mostFrequentValue, maxFrequency);
    }

    private static DiceResultsAnalysis AnalyzeDiceResults(int[] diceResults, int mostFrequentValue, int frequency)
    {
        List<int> otherValues = [];

        foreach (int diceResult in diceResults)
        {
            if (diceResult != mostFrequentValue)
            {
                otherValues.Add(diceResult);
            }
        }

        return new DiceResultsAnalysis(mostFrequentValue, frequency, otherValues);
    }

    private static int ApplyScoreRule(DiceResultsAnalysis analysis)
    {
        (int mostFrequentValue, int mostFrequentValueFrequency, List<int> otherValues) = analysis;

        if (mostFrequentValueFrequency == 4)
        {
            return 1111 * mostFrequentValue;
        }

        if (mostFrequentValueFrequency == 3)
        {
            int baseScore = 10 * mostFrequentValue + otherValues[0];
            return baseScore * baseScore;
        }

        if (mostFrequentValueFrequency == 2)
        {
            if (otherValues[0] == otherValues[1])
            {
                return (mostFrequentValue + otherValues[0]) *
                       int.Abs(mostFrequentValue - otherValues[0]);
            }
            else
            {
                return otherValues[0] * otherValues[1];
            }
        }

        if (mostFrequentValueFrequency == 1)
        {
            return int.Min(
                int.Min(mostFrequentValue, otherValues[0]),
                int.Min(otherValues[1], otherValues[2])
            );
        }

        throw new InvalidOperationException();
    }
}

/*

1부터 6까지 숫자가 적힌 "주사위가 네 개"
네 주사위를 굴렸을 때 나온 숫자에 따라 다음과 같은 "점수"를 얻습니다.

1
네 주사위에서 나온 숫자가 모두 p로 같다면
1111 × p점을 얻습니다.

2
세 주사위에서 나온 숫자가 p로 같고 나머지 다른 주사위에서 나온 숫자가 q(p ≠ q)라면
(10 × p + q)2 점을 얻습니다.

3
주사위가 두 개씩 같은 값이 나오고, 나온 숫자를 각각 p, q(p ≠ q)라고 한다면
(p + q) × |p - q|점을 얻습니다.

4
어느 두 주사위에서 나온 숫자가 p로 같고 나머지 두 주사위에서 나온 숫자가 각각 p와 다른 q, r(q ≠ r)이라면
q × r점을 얻습니다.

5
네 주사위에 적힌 숫자가 모두 다르다면
나온 숫자 중 가장 작은 숫자 만큼의 점수를 얻습니다.

네 주사위를 굴렸을 때 나온 숫자가 정수 매개변수 a, b, c, d로 주어질 때, 얻는 점수를 return 하는 solution 함수를 작성해 주세요.

*/

/*

전략

네 개가 같은가? => 같은 것의 값; 나머지들의 값
세 개가 같은가? => 같은 것의 값; 나머지들의 값
두 개가 같은가? => 같은 것의 값; 나머지들의 값
한 개가 같은가? => 같은 것의 값; 나머지들의 값

*/