# Memory-Leak-Logger

A lightweight tool to detect and log memory leaks.  
It tracks memory usage over time, identifies abnormal growth, and provides easy-to-read reports.

---

## ✨ Features
- Detects potential memory leaks by monitoring process memory.
- CLI and library usage.
- Supports JSON, CSV, and NDJSON outputs.
- Configurable sampling intervals.
- CI/CD friendly – fail builds on detected leaks.
- Cross-platform (Linux, Windows, macOS).

---

## 📦 Installation

### Python
```bash
pip install memory-leak-logger

FetchContent_Declare(
  mll
  GIT_REPOSITORY https://github.com/your-org/Memory-Leak-Logger.git
  GIT_TAG v1.0.0
)
FetchContent_MakeAvailable(mll)
target_link_libraries(your_target PRIVATE mll)
# Monitor a Python script with 500ms sampling
mll run --sample-interval 0.5s --output mll.json -- python app.py

from mll import LeakLogger

logger = LeakLogger(sample_interval="0.5s", output="mll.json")
logger.start()

# Your code...
data = []
for i in range(10000):
    data.append(bytearray(1024))

logger.stop().

#include <mll/mll.hpp>

int main() {
  mll::LeakLogger logger({.sample_interval = std::chrono::milliseconds(500),
                          .output = "mll.csv"});
  logger.start();

  std::vector<std::unique_ptr<char[]>> blobs;
  for (int i = 0; i < 10000; ++i)
    blobs.emplace_back(std::make_unique<char[]>(1024));

  logger.stop();
}
