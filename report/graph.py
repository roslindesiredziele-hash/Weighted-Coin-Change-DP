import pandas as pd
import matplotlib.pyplot as plt

# Load benchmark data
df = pd.read_csv("./data/benchmark.csv")

# -----------------------------
# Standard Runtime Comparison
# -----------------------------

plt.figure(figsize=(10, 6))

plt.plot(
    df["Amount"],
    df["TimeMs"],
    marker="o",
    linewidth=2,
    markersize=6,
    color="royalblue"
)

plt.title(
    "Weighted Coin Change DP Runtime"
)

plt.xlabel(
    "Target Amount"
)

plt.ylabel(
    "Execution Time (ms)"
)

plt.grid(
    True,
    linestyle="--",
    alpha=0.6
)

plt.tight_layout()

plt.savefig(
    "./report/runtime_comparison.png",
    dpi=300
)

# -----------------------------
# Logarithmic Runtime Comparison
# -----------------------------

plt.figure(figsize=(10, 6))

plt.plot(
    df["Amount"],
    df["TimeMs"],
    marker="o",
    linewidth=2,
    markersize=6,
    color="darkgreen"
)

plt.xscale("log")
plt.yscale("log")

plt.title(
    "Weighted Coin Change DP Runtime (Log-Log Scale)"
)

plt.xlabel(
    "Target Amount (log scale)"
)

plt.ylabel(
    "Execution Time (ms, log scale)"
)

plt.grid(
    True,
    which="both",
    linestyle="--",
    alpha=0.6
)

plt.tight_layout()

plt.savefig(
    "./report/runtime_logarithmic.png",
    dpi=300
)

print("Generated:")
print("  report/runtime_comparison.png")
print("  report/runtime_logarithmic.png")

plt.show()