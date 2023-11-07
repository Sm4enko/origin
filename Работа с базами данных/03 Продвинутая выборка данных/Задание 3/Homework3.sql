CREATE DATABASE music_collection;

\c music_collection;

CREATE TABLE artists (
    artist_id SERIAL PRIMARY KEY,
    artist_name VARCHAR(255) NOT NULL
);

CREATE TABLE genres (
    genre_id SERIAL PRIMARY KEY,
    genre_name VARCHAR(255) NOT NULL
);

CREATE TABLE albums (
    album_id SERIAL PRIMARY KEY,
    album_name VARCHAR(255) NOT NULL,
    genre_id INT REFERENCES genres(genre_id),
    release_date DATE
);

CREATE TABLE album_artists (
    album_id INT REFERENCES albums(album_id),
    artist_id INT REFERENCES artists(artist_id),
    PRIMARY KEY (album_id, artist_id)
);

CREATE TABLE tracks (
    track_id SERIAL PRIMARY KEY,
    track_name VARCHAR(255) NOT NULL,
    album_id INT REFERENCES albums(album_id),
    duration INTERVAL
);

CREATE TABLE compilations (
    compilation_id SERIAL PRIMARY KEY,
    compilation_name VARCHAR(255) NOT NULL
);

INSERT INTO artists (artist_name) VALUES
    ('Исполнитель 1'),
    ('Исполнитель 2'),
    ('Исполнитель 3'),
    ('Исполнитель 4'),
    ('Исполнитель 5');

INSERT INTO genres (genre_name) VALUES
    ('Попса'),
    ('Рок'),
    ('Классика');

INSERT INTO albums (album_name, genre_id, release_date) VALUES
    ('Альбом 1', 1, '2003-05-12'),
    ('Альбом 2', 2, '2004-09-20'),
    ('Альбом 3', 3, '2005-12-15');

-- Исправленная часть с добавлением альбомов
INSERT INTO albums (album_name, genre_id, release_date) VALUES
    ('Альбом 4', 1, '2006-03-08');
-- Конец исправленной части

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

INSERT INTO compilations (compilation_name) VALUES
    ('Сборник 1'),
    ('Сборник 2'),
    ('Сборник 3'),
    ('Сборник 4'),
    ('Сборник 5');

SELECT g.genre_name, COUNT(aa.artist_id) AS artist_count
FROM genres g
LEFT JOIN albums al ON g.genre_id = al.genre_id
LEFT JOIN album_artists aa ON al.album_id = aa.album_id
GROUP BY g.genre_name;

SELECT COUNT(t.track_id) AS track_count
FROM tracks t
JOIN albums al ON t.album_id = al.album_id
WHERE al.release_date BETWEEN '2019-01-01' AND '2020-12-31';

SELECT al.album_name, AVG(EXTRACT(epoch FROM t.duration)) AS avg_duration_seconds
FROM albums al
JOIN tracks t ON al.album_id = t.album_id
GROUP BY al.album_name;

SELECT a.artist_name
FROM artists a
LEFT JOIN album_artists aa ON a.artist_id = aa.artist_id
LEFT JOIN albums al ON aa.album_id = al.album_id AND al.release_date BETWEEN '2019-01-01' AND '2020-12-31'
WHERE al.album_id IS NULL;

SELECT DISTINCT c.compilation_name
FROM compilations c
JOIN tracks t ON c.compilation_id = t.compilation_id
JOIN albums al ON t.album_id = al.album_id
JOIN artists a ON al.artist_id = a.artist_id
WHERE a.artist_name = 'Джэк';
