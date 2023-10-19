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

INSERT INTO tracks (track_name, album_id, duration) VALUES
    ('Трек 1', 1, '00:03:45'),
    ('Трек 2', 1, '00:04:20'),
    ('Трек 3', 2, '00:02:50'),
    ('Трек 4', 3, '00:05:15'),
    ('Трек 5', 3, '00:03:30');

INSERT INTO compilations (compilation_name, release_date) VALUES
    ('Коллекция 1', '2006-01-15'),
    ('Коллекция 2', '2007-03-22'),
    ('Коллекция 3', '2005-11-10'),
    ('Коллекция 4', '2008-05-05'),
    ('Коллекция 5', '2006-09-30');
