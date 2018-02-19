#ifndef kafe_libs_benchmark
#define kafe_libs_benchmark

#include <iostream>
#include <algorithm>
#include <vector>
#include <chrono>

#define BENCHMARK_INIT() benchmark::Main benchmarkobj; benchmarkobj.start();
#define BENCHMARK_STOP() benchmarkobj.stop();
#define BENCHMARK(f) BENCHMARK_INIT() f; BENCHMARK_STOP()
#define BENCHMARK_FORMAT(name, r, mode) benchmarkobj.format(name, r, benchmarkobj.to_##mode().count(), #mode);
#define BENCHMARK_FMT_TICKS(name, mode) benchmarkobj.format_ticks(name, #mode);
// format output (single run)
#define BENCHMARK_F(name, f, mode) { BENCHMARK(f) BENCHMARK_FORMAT(name, 1, mode) }
// multiple runs
#define BENCHMARK_MR(name, f, r, mode) { BENCHMARK_INIT() for (int current_iteration=0; current_iteration < r; current_iteration++) { f; } BENCHMARK_STOP() BENCHMARK_FORMAT(name, r, mode) }
// multiple runs + min|max
#define BENCHMARK_MRSTATS(name, f, r, mode) { BENCHMARK_INIT() for (int current_iteration=0; current_iteration < r; current_iteration++) { f; benchmarkobj.tick(); } BENCHMARK_FMT_TICKS(name, mode) }

namespace benchmark
{
    class Main
    {
    private:
        typedef std::chrono::high_resolution_clock clock_t;
        clock_t::time_point m_start;
        std::vector<clock_t::duration> m_ticks;
        clock_t::time_point m_stop;

    public:
        Main() :
            m_start(clock_t::now())
            , m_stop(m_start)
        {}

        ~Main() {}

        void start()
        {
            m_start = clock_t::now();
        }

        void stop()
        {
            m_stop = clock_t::now();
        }

        void tick()
        {
            stop();
            m_ticks.push_back(ticks());
            start();
        }

        clock_t::duration ticks() const
        {
            return m_stop - m_start;
        }

        template<typename T>
        void format(const std::string& name, int r, T val, const std::string& mode)
        {
            if (name != "")
                std::cerr << "Benchmark of " << name << " on ";
            else
                std::cerr << "Benchmark on ";
            std::cerr << r << " run(s) = " << val << mode << std::endl;
            if (r > 1)
                std::cerr << "Average = " << val / double(r) << mode << std::endl;
        }

        void format_ticks(const std::string& name, const std::string& mode)
        {
            if (name != "")
                std::cerr << "Benchmark of " << name << " on ";
            else
                std::cerr << "Benchmark on ";
            std::cerr << m_ticks.size() << " run(s) = ";

            clock_t::duration total(std::chrono::nanoseconds::zero());
            clock_t::duration t_max(std::chrono::nanoseconds::zero()), t_min(std::chrono::nanoseconds::zero());
            for (auto t : m_ticks)
            {
                if (t > t_max)
                    t_max = t;
                if (t < t_min || t_min == std::chrono::nanoseconds::zero())
                    t_min = t;
                total += t;
            }

            std::sort(m_ticks.begin(), m_ticks.end());
            clock_t::duration median;
            if (m_ticks.size() % 2 == 0)
                median = m_ticks[m_ticks.size() / 2];
            else
                median = m_ticks[(1 + m_ticks.size()) / 2];

            if (mode == "ns")
                std::cerr << to_ticks<std::chrono::nanoseconds>(total).count() << mode << ", "
                          << "min = " << to_ticks<std::chrono::nanoseconds>(t_min).count() << mode << ", "
                          << "max = " << to_ticks<std::chrono::nanoseconds>(t_max).count() << mode << ", "
                          << "average = " << to_ticks<std::chrono::nanoseconds>(total).count() / double(m_ticks.size()) << mode << ", "
                          << "median = " << to_ticks<std::chrono::nanoseconds>(median).count() << mode
                          << std::endl;
            else if (mode == "us")
                std::cerr << to_ticks<std::chrono::microseconds>(total).count() << mode << ", "
                          << "min = " << to_ticks<std::chrono::microseconds>(t_min).count() << mode << ", "
                          << "max = " << to_ticks<std::chrono::microseconds>(t_max).count() << mode << ", "
                          << "average = " << to_ticks<std::chrono::microseconds>(total).count() / double(m_ticks.size()) << mode << ", "
                          << "median = " << to_ticks<std::chrono::microseconds>(median).count() << mode
                          << std::endl;
            else if (mode == "ms")
                std::cerr << to_ticks<std::chrono::milliseconds>(total).count() << mode << ", "
                          << "min = " << to_ticks<std::chrono::milliseconds>(t_min).count() << mode << ", "
                          << "max = " << to_ticks<std::chrono::milliseconds>(t_max).count() << mode << ", "
                          << "average = " << to_ticks<std::chrono::milliseconds>(total).count() / double(m_ticks.size()) << mode << ", "
                          << "median = " << to_ticks<std::chrono::milliseconds>(median).count() << mode
                          << std::endl;
            else
                std::cerr << "INVALID UNIT";
        }

        template<typename T>
        T to_ticks(clock_t::duration i=clock_t::duration(std::chrono::nanoseconds(0))) const
        {
            if (i == clock_t::duration(std::chrono::nanoseconds(0)))
                return std::chrono::duration_cast<T>(ticks());
            return std::chrono::duration_cast<T>(i);
        }

        std::chrono::milliseconds to_ms() const
        {
            return to_ticks<std::chrono::milliseconds>();
        }

        std::chrono::microseconds to_us() const
        {
            return to_ticks<std::chrono::microseconds>();
        }

        std::chrono::nanoseconds to_ns() const
        {
            return to_ticks<std::chrono::nanoseconds>();
        }
    };
}  // namespace benchmark

#endif  // kafe_libs_benchmark
