from sklearn.datasets import load_wine
from sklearn.preprocessing import StandardScaler
from sklearn.cluster import KMeans
from sklearn.metrics import silhouette_score
import matplotlib.pyplot as plt

data = load_wine()
X = StandardScaler().fit_transform(data.data)

k_values = range(2, 9)
inertias = []
silhouettes = []

for k in k_values:
    model = KMeans(n_clusters=k, random_state=42, n_init=10)
    labels = model.fit_predict(X)
    inertias.append(model.inertia_)
    silhouettes.append(silhouette_score(X, labels))

print("k  Inertia  Silhouette")
for k, i, s in zip(k_values, inertias, silhouettes):
    print(k, round(i, 2), round(s, 3))

plt.plot(list(k_values), inertias, marker="o")
plt.xlabel("Number of clusters (k)")
plt.ylabel("Inertia")
plt.title("Elbow Method")
plt.grid(True)
plt.show()

plt.plot(list(k_values), silhouettes, marker="o")
plt.xlabel("Number of clusters (k)")
plt.ylabel("Silhouette Score")
plt.title("Silhouette Method")
plt.grid(True)
plt.show()

best_k = list(k_values)[silhouettes.index(max(silhouettes))]
print("Best k by maximum silhouette score:", best_k)
