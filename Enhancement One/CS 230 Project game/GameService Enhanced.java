package com.gamingroom;

import java.util.ArrayList;
import java.util.List;

/**
 * A singleton service for the game engine.
 */
public class GameService {
    /** A list of the active games */
    private final List<Game> games = new ArrayList<>();

    /** Counters for next available IDs */
    private long nextGameId = 1;
    private long nextTeamId = 1;
    private long nextPlayerId = 1;

    /** Singleton instance */
    private static final GameService instance = new GameService();

    /** Private constructor to enforce singleton */
    private GameService() {}

    /** Accessor for singleton instance */
    public static GameService getInstance() {
        return instance;
    }

    /**
     * Adds a game if it doesn't already exist.
     * 
     * @param name Unique name of the game
     * @return Existing or newly created game instance
     */
    public Game addGame(String name) {
        Game existing = getGame(name);
        if (existing != null) {
            return existing;
        }

        Game newGame = new Game(nextGameId++, name);
        games.add(newGame);
        return newGame;
    }

    /** Returns the game at a specific index (package-private for testing) */
    Game getGame(int index) {
        return games.get(index);
    }

    /** Retrieves a game by ID */
    public Game getGame(long id) {
        for (Game game : games) {
            if (game.getId() == id) {
                return game;
            }
        }
        return null;
    }

    /** Retrieves a game by name */
    public Game getGame(String name) {
        for (Game game : games) {
            if (game.getName().equalsIgnoreCase(name)) {
                return game;
            }
        }
        return null;
    }

    /** Returns the number of active games */
    public int getGameCount() {
        return games.size();
    }

    /** Returns the next player ID */
    public long getNextPlayerId() {
        return nextPlayerId++;
    }

    /** Returns the next team ID */
    public long getNextTeamId() {
        return nextTeamId++;
    }
}