CREATE DATABASE music_collection;

\c music_collection;

CREATE TABLE artists (
    artist_id SERIAL PRIMARY KEY,
    artist_name VARCHAR(255) NOT NULL
);

INSERT INTO artists (artist_name) VALUES
    ('Певец 1'),
    ('Певец 2'),
    ('Певец 3'),
    ('Певец 4'),
    ('Певец 5');

CREATE TABLE genres (
    genre_id SERIAL PRIMARY KEY,
    genre_name VARCHAR(255) NOT NULL
);

INSERT INTO genres (genre_name) VALUES
    ('Попса'),
    ('Рок'),
    ('Классика');

CREATE TABLE albums (
    album_id SERIAL PRIMARY KEY,
    album_name VARCHAR(255) NOT NULL,
    artist_id INT REFERENCES artists(artist_id),
    genre_id INT REFERENCES genres(genre_id)
);

INSERT INTO albums (album_name, artist_id, genre_id) VALUES
    ('Альбом 1', 1, 1),
    ('Альбом 2', 2, 2),
    ('Альбом 3', 3, 3),
    ('Альбом 4', 4, 1);

CREATE TABLE tracks (
    track_id SERIAL PRIMARY KEY,
    track_name VARCHAR(255) NOT NULL,
    album_id INT REFERENCES albums(album_id),
    duration INTERVAL
);

INSERT INTO tracks (track_name, album_id, duration) VALUES
    ('Трек 1', 1, '00:03:45'),
    ('Трек 2', 1, '00:04:20'),
    ('Трек 3', 2, '00:02:50'),
    ('Трек 4', 3, '00:05:15'),
    ('Трек 5', 3, '00:03:30');

CREATE TABLE compilations (
    compilation_id SERIAL PRIMARY KEY,
    compilation_name VARCHAR(255) NOT NULL,
    release_date DATE
);

INSERT INTO compilations (compilation_name, release_date) VALUES
    ('Коллекция 1', '2006-01-15'),
    ('Коллекция 2', '2007-03-22'),
    ('Коллекция 3', '2005-11-10'),
    ('Коллекция 4', '2008-05-05'),
    ('Коллекция 5', '2006-09-30');

SELECT track_name, duration FROM tracks;

SELECT track_name, duration
FROM tracks
WHERE duration > '00:02:20';

SELECT compilation_name
FROM compilations
WHERE EXTRACT(YEAR FROM release_date) BETWEEN 2018 AND 2020;

SELECT artist_name
FROM artists
WHERE artist_name NOT LIKE '% %';

SELECT track_name
FROM tracks
WHERE track_name LIKE '%test%';
