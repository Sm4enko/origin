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
    genre_id INT REFERENCES genres(genre_id)
);

CREATE TABLE album_artists (
    album_id INT REFERENCES albums(album_id),
    artist_id INT REFERENCES artists(artist_id),
    PRIMARY KEY (album_id, artist_id)
);

CREATE TABLE tracks (
    track_id SERIAL PRIMARY KEY,
    track_name VARCHAR(255) NOT NULL,
    album_id INT REFERENCES albums(album_id)
);

CREATE TABLE compilations (
    compilation_id SERIAL PRIMARY KEY,
    compilation_name VARCHAR(255) NOT NULL
);
