(
    SELECT
        Users.name AS results
    FROM
        Users
        JOIN MovieRating ON Users.user_id = MovieRating.user_id
    GROUP BY
        Users.user_id
    ORDER BY
        COUNT(*) DESC,
        Users.name
    LIMIT
        1
)
UNION ALL
(
    SELECT
        Movies.title AS results
    FROM
        Movies
        JOIN MovieRating ON Movies.movie_id = MovieRating.movie_id
    WHERE
        MovieRating.created_at BETWEEN '2020-02-01'
        AND '2020-02-29'
    GROUP BY
        Movies.movie_id
    ORDER BY
        AVG(rating) DESC,
        Movies.title
    LIMIT
        1
);