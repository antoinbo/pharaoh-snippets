meta:
  id: highscore
  title: Pharaoh highscore file
  application: Pharaoh game
  file-extension: jas
  encoding: ascii
  endian: le
doc: |
  Pharaoh highscore file structure.
seq:
  - id: entries
    type: entry
    repeat: eos
types:
  entry:
    seq:
      - id: score
        type: u4
      - id: id
        type: u4
      - id: name
        type: str
        size: 40
        encoding: ASCII
      - id: percent
        type: u4
      - id: population
        type: u4
      - id: money
        type: u4
      - id: year
        type: u4
      - id: difficulty
        type: u4
        enum: difficulty
      - id: unknown
        type: u4
      - id: active
        type: u4
enums:
  difficulty:
    0: veryeasy
    1: easy
    2: normal
    3: hard
    4: impossible
