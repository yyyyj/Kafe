#ifndef kafe_libs_benchmark
#define kafe_libs_benchmark

#include <iostream>
#include <chrono>

#define BENCHMARK_INIT() benchmark::Main benchmarkobj; benchmarkobj.start();
#define BENCHMARK_STOP() benchmarkobj.stop();
#define BENCHMARK(f) BENCHMARK_INIT() f; BENCHMARK_STOP()
#define BENCHMARK_FORMAT(name, r, mode) benchmarkobj.format(name, r, benchmarkobj.to_##mode().count(), #mode);
// format output (single run)
#define BENCHMARK_F(name, f, mode) { BENCHMARK(f) BENCHMARK_FORMAT(name, 1, mode) }
// multiple runs
#define BENCHMARK_MR(name, f, r, mode) { BENCHMARK_INIT() for (int current_iteration=0; current_iteration < r; current_iteration++) { f; } BENCHMARK_STOP() BENCHMARK_FORMAT(name, r, mode) }

namespace benchmark
{
    class Main
    {
    private:
        typedef std::chrono::high_resolution_clock clock_t;
        clock_t::time_point m_start;
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

        clock_t::duration ticks() const
        {
            return m_stop - m_start;
        }

        template<typename T>
        void format(const std::string& name, int r, T val, const std::string& mode)
        {
            if (name != "")
                { std::cerr << "Benchmark of " << name << " on "; }
            else
                { std::cerr << "Benchmark on "; }
            std::cerr << r << " run(s) = " << val << mode << std::endl;
            if (r > 1)
                { std::cerr << "Average = " << val / double(r) << mode << std::endl; }
        }

        template<typename T>
        T to_ticks() const
        {
            return std::chrono::duration_cast<T>(ticks());
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
