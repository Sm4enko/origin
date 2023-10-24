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
    album_id INT REFERENCES albums(album_id)
);

INSERT INTO tracks (track_name, album_id) VALUES
    ('Трек 1', 1),
    ('Трек 2', 1),
    ('Трек 3', 2),
    ('Трек 4', 3),
    ('Трек 5', 3);

CREATE TABLE compilations (
    compilation_id SERIAL PRIMARY KEY,
    compilation_name VARCHAR(255) NOT NULL
);

INSERT INTO compilations (compilation_name) VALUES
    ('Коллекция 1'),
    ('Коллекция 2'),
    ('Коллекция 3'),
    ('Коллекция 4'),
    ('Коллекция 5');
