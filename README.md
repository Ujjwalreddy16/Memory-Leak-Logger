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
