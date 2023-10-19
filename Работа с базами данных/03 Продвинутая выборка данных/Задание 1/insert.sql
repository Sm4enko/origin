INSERT INTO artists (artist_name) VALUES
    ('Певец 1'),
    ('Певец 2'),
    ('Певец 3'),
    ('Певец 4'),
    ('Певец 5');

INSERT INTO genres (genre_name) VALUES
    ('Попса'),
    ('Рок'),
    ('Классика');

INSERT INTO albums (album_name, genre_id) VALUES
    ('Альбом 1', 1),
    ('Альбом 2', 2),
    ('Альбом 3', 3),
    ('Альбом 4', 1);

INSERT INTO album_artists (album_id, artist_id) VALUES
    (1, 1),
    (2, 2),
    (3, 3),
    (4, 4);

INSERT INTO tracks (track_name, album_id) VALUES
    ('Трек 1', 1),
    ('Трек 2', 1),
    ('Трек 3', 2),
    ('Трек 4', 3),
    ('Трек 5', 3);

INSERT INTO compilations (compilation_name) VALUES
    ('Коллекция 1'),
    ('Коллекция 2'),
    ('Коллекция 3'),
    ('Коллекция 4'),
    ('Коллекция 5');
