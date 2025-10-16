from fractions import Fraction
f = Fraction(108/128).limit_denominator(7)
r = f.denominator
s = f.numerator
print(f"estimated phase = {s}/{r}")
