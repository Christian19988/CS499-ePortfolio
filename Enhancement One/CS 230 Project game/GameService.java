package com.gamingroom;

import java.util.ArrayList;
import java.util.List;

/**
 * A singleton service for the game engine
 * 
 * @author Oyetunde Oloyede
 */
public class GameService {
    /** A list of the active games */
    private static List<Game> games = new ArrayList<Game>();

    /** Holds the next game identifier */
    private static long nextGameId = 1;

    /** Holds the next team identifier */
    private static long nextTeamId = 1;

    /** Holds the next player identifier */
    private static long nextPlayerId = 1;

    //@field singleton initialized to null
    private static GameService service = new GameService();

    /** A private constructor. It is normal for a singleton to have a private
     * constructor so that we don't instantiate any additional instances
     * outside of this class.
     */
    private GameService() {}

    /** A public accessor for our instance. This allows outside classes to
     * access objects in this singleton class.
     */
    public static GameService getInstance() {
        return service;
    }

    /** Construct a new game instance
     * 
     * @param name the unique name of the game
     * @return the game instance (new or existing)
     */
    
    public Game addGame(String name) {
        // Initialize a local game instance
        Game game = null;

        // Iterate through existing games to check if the game name already exists
        for (int i = 0; i < getGameCount(); ++i) {
            if (name.equalsIgnoreCase(games.get(i).getName())) {
                // If the game name exists, assign it to the local game instance
                game = games.get(i);
            }
        }

        // If the game name doesn't exist, create a new game instance and add it to the list of games
        if (game == null) {
            game = new Game(nextGameId++, name);
            games.add(game);
        }

        // Return the new/existing game instance to the caller
        return game;
    }
   

    In this updated comment, I've provided a clearer explanation of each step within the method, emphasizing the purpose of each block of code.

    /** Returns the game instance at the specified index.
     * <p>
     * Scope is package/local for testing purposes.
     * </p>
     * 
     * @param index index position in the list to return
     * @return requested game instance
     */
    Game getGame(int index) {
        return games.get(index);
    }

    /** Returns the game instance with the specified id.
     * 
     * @param id unique identifier of game to search for
     * @return requested game instance
     */
    public Game getGame(long id) {
        // a local game instance
        Game game = null;

     // Iterate through existing games to check if the game name already exists
        for (int i = 0; i < getGameCount(); ++i) {
            if (games.get(i).getId() == id) {
                game = games.get(i);
            }
        }
        return game;
    }

    /** Returns the game instance with the specified name.
     * 
     * @param name unique name of game to search for
     * @return requested game instance
     */
    public Game getGame(String name) {
        // a local game instance
        Game game = null;

        // this iterator method searches through the array of games and
        // checks if there is a game with the name of the game we want to add
        for (int i = 0; i < getGameCount(); ++i) {
            if (name.equalsIgnoreCase(games.get(i).getName())) {
                game = games.get(i);
            }
        }
        return game;
    }

    /** Returns the number of games currently active
     * 
     * @return the number of games currently active
     */
    public int getGameCount() {
        return games.size();
    }

    /** returns the Id of the next player
     * 
     * @return the id of the next player
     */
    public long getNextPlayerId() {
        return nextPlayerId++;
    }

    /** returns the Id of the next team
     * 
     * @return the Id of the next team
     */
    public long getNextTeamId() {
        return nextTeamId++;
    }
}