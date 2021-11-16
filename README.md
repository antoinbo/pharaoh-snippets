# pharaoh-snippets

## Highscore file structure

Pharaoh highscore file format description.

This small project is made to learn how to use Kaitai.

### Build

Via pip:
```
cd highscore
pip install kaitaistruct
ksc -t python highscore.ksy
```

Via docker:
```
cd highscore
docker build -t kaitai-docker .
docker run -v "$(pwd):/root:rw" kaitai-docker ksc -t python highscore.ksy
```

### Usage

```py
data = Highscore.from_file("highscore.jas")

print(len(data.entries))
print(len([e for e in data.entries if e.active]))

for entry in data.entries:
    if entry.active:
        print(entry.score, entry.id, entry.name, entry.percent, entry.population, entry.money, entry.year, entry.difficulty, entry.unknown, entry.active)
```
