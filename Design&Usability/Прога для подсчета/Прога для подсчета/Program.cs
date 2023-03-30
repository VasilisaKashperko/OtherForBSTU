using System;

namespace Прога_для_подсчета
{
    class Program
    {
        static void Main(string[] args)
        {
            dynamic H = 0.4m;
            dynamic P = 1.1m;
            dynamic K = 0.28m;
            dynamic M = 0.1m;
            dynamic D = 1.2m;

            dynamic web3_1 = H + D + P + M + H + D + 7 * K + H + D + P + M + D + 2 * H + 2 * M + 2 * H + 2 * M + H + M;
            Console.WriteLine(web3_1);

            dynamic web3_2 = H + D + P + M + P + M + D + P + M + D + 2 * H + 2 * M + 2 * H + 2 * M + H + M;
            Console.WriteLine(web3_2);

            dynamic web2_2 = H + D + P + M + P + M + D + 2 * H + 2 * M + H + M+D+ 2 * H + 2 * M + H + M;
            Console.WriteLine(web2_2);

            dynamic web1_1 = H + D + P + M + H + D + 7 * K + H + D + P + M + D + 2 * H + 2 * M + D + 2 * H + 2 * M + H + M;
            Console.WriteLine(web1_1);

            dynamic web1_2 = H + D + P + M + D + 2 * H + 2 * M + D + 2 * H + 2 * M + D + 2 * H + 2 * M + H + M;
            Console.WriteLine(web1_2);
        }
    }
}
