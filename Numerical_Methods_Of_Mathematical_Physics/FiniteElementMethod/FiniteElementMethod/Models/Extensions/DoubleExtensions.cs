﻿namespace FiniteElementMethod.Models.Extensions
{
    static class DoubleExtensions
    {
        public static bool IsApproximatelyEqualTo(this double initialValue, double value)
        {
            return IsApproximatelyEqualTo(initialValue, value, 0.00001);
        }

        public static bool IsApproximatelyEqualTo(this double initialValue, double value, double maximumDifferenceAllowed)
        {
            // Handle comparisons of floating point values that may not be exactly the same
            return System.Math.Abs(initialValue - value) < maximumDifferenceAllowed;
        }
    }
}
