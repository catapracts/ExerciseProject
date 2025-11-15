using System.Collections;
using System.Collections.Generic;
using System.Collections.ObjectModel;
using System.Linq;

namespace Practice;

struct Foo : IEnumerable<int>
{
    struct Enumerator : IEnumerator<int>
    {
        private int _currentValue;
        private readonly int _endValue;
        private readonly int _startValue;

        public Enumerator(int startValue, int endValue)
        {
            _currentValue = startValue - 1;
            _startValue = startValue;
            _endValue = endValue;
        }

        // Property
        public readonly int Current => _currentValue; // Getter

        readonly object IEnumerator.Current => Current;

        public void Dispose() { }

        public bool MoveNext() => ++_currentValue < _endValue;

        public void Reset() => _currentValue = _startValue;
    }

    public int CurrentValue { get; set; }
    public IEnumerator<int> GetEnumerator() => new Enumerator(CurrentValue, CurrentValue + 10);

    IEnumerator IEnumerable.GetEnumerator() => GetEnumerator();
}

internal class Program
{
    static void Main()
    {
        //int[] array = [10, 20, 30, 40, 50]; // 구버전은 {}
        
        //foreach(int i in array)
        //{
            Foo foo = new Foo
            {
                CurrentValue = 200
            };

            foreach(int item in foo)
            {
                Console.WriteLine(item);
            }
        //}
    }
}
